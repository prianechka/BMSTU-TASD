#include "process.h"


void process_model_array()
{
    struct queue_array array;
    init_queue_array(&array);

    long int count_first_request = 0, count_second_request = 1;
    long int count_first_in_queue = 0, count_second_in_queue = 1;
    long int count_len_queue = 0, len_queue = 0;
    long int events = 0, event_OA = 0;
    double not_do_OA = 0, all_time = 0;

    double time_in_OA = 0;

    double t_1, t_OA;

    t_1 = generate_time(0, 5);
    t_OA = generate_time(0, 4);
    int type = 2;

    int flag = 0;

    clock_t start, stop;
    start = clock();
    while (count_first_request < MAX_WORK)
    {
        count_len_queue += len_queue;
        events++;
        if (t_OA == 0)
        {
            if (type == 1)
            {
                count_first_request++;
                flag = 0;
            }
            else
            {
                count_second_request++;
                if ((array.last - array.first) < 4)
                    add_queue_array(&array, 2);
                else
                {
                    add_queue_array(&array, 1);
                    array.queue[array.first + 4] = 2;
                }
                count_second_in_queue++;
                len_queue++;
            }
            if (is_empty_array(&array) == not)
            {
                len_queue--;
                type = pop_queue_array(&array);
                t_OA = generate_time(TIME_OA_0, TIME_OA_1);
                time_in_OA += t_OA;
                event_OA++;
            }
            else
                not_do_OA += t_1;
        }

        if ((t_1 == 0) && (len_queue < MAX_Q))
        {
            len_queue++;
            count_first_in_queue++;
            add_queue_array(&array, 1);
            t_1 = generate_time(TIME_1_0, TIME_1_1);
        }

        double t_next = fmin(t_1, t_OA);
        t_1 -= t_next;
        t_OA -= t_next;
        all_time += t_next;

        if ((count_first_request) % 100 == 0 && count_first_request != 0 && flag == 0)
        {
            printf("���������� ��� ������������ ������ 1-�� ����: %ld\n", count_first_request);
            printf("------------------------------\n");
            printf("������� ������ �������: %ld\n", len_queue);
            printf("������� ������ �������: %lf\n", (double)count_len_queue / (double)events);
            printf("������� ����� ������� � �������: %f �������� ������\n", (double)count_len_queue / (double)events * (double)time_in_OA / (double)event_OA);
            printf("------------------------------\n\n");
            flag = 1;
        }
    }
    stop = clock();
    double time = ((double)stop - (double)start) / CLK_TCK;
    double t_median_OA = (TIME_OA_1 + TIME_OA_0)/2 * MAX_WORK;
    double t_median_1 = (TIME_1_1 + TIME_1_0)/2 * MAX_WORK;
    double expected_time = 0;
    if (t_median_1 > t_median_OA)
        expected_time = t_median_1;
    else
        expected_time = t_median_OA + (TIME_1_1 + TIME_1_0)/2 * count_second_in_queue;
    printf("------------------------------\n");
    printf("����� ����� ������ ���������: %d �������� ������\n", (int)all_time);
    printf("��������� ����� ������ ���������: %d �������� ������\n", (int)expected_time);
    printf("����������� ���������� ������� ������: %.3f%%\n", fabs(all_time - expected_time)/expected_time * 100);
    printf("����� ������ ��������� � ��������: %f ������\n\n", time);
    printf("����� ������� �������� - %.1f �������� ������\n", not_do_OA);
    printf("���������� ������ ������ ������� - %ld, ����� ���� � ������� - %ld\n", count_first_request, count_first_in_queue);
    printf("���������� ������ ������ ������� - %ld, ����� ���� � ������� - %ld\n", count_second_request, count_second_in_queue);
    printf("������� ������ �������: %f �������\n", (double)count_len_queue / (double)events);
    printf("������� ����� ������� � �������: %f �������� ������\n", (double)count_len_queue / (double)events * (double)time_in_OA / (double)event_OA);
}


void process_model_list()
{
    struct queue_list allist;
    struct queue_list *list = &allist;
    list->first = (struct leaf*) malloc(sizeof(struct leaf));
    list->last = (struct leaf*) malloc(sizeof(struct leaf));
    list->first->next = list->last;
    list->first->value = 0;
    list->last->next = NULL;
    list->last->value = 0;

    long int count_first_request = 0, count_second_request = 1;
    long int count_first_in_queue = 0, count_second_in_queue = 1;
    long int count_len_queue = 0, len_queue = 0;
    long int events = 0, event_OA = 0;
    double not_do_OA = 0, all_time = 0;
    double time_in_OA = 0;

    double t_1, t_OA;

    t_1 = generate_time(0, 5);
    t_OA = generate_time(0, 4);
    int type = 2;

    int flag = 0;

    clock_t start, stop;
    start = clock();
    while (count_first_request < MAX_WORK)
    {
        count_len_queue += len_queue;
        events++;
        if (t_OA == 0)
        {
            if (type == 1)
            {
                count_first_request++;
                flag = 0;
            }
            else
            {
                count_second_request++;
                if (len_queue < 4)
                    add_queue_list(&list, 2);
                else
                {
                    add_queue_list(&list, 1);
                    struct leaf *tmp = list->first->next;
                    for (int i = 0; i < 4; i++)
                        tmp = tmp->next;
                    tmp->value = 2;
                }
                count_second_in_queue++;
                len_queue++;
            }
            if (len_queue > 0)
            {
                len_queue--;
                type = pop_queue_list(&list);
                t_OA = generate_time(TIME_OA_0, TIME_OA_1);
                time_in_OA += t_OA;
                event_OA++;
            }
            else
                not_do_OA += t_1;
        }

        if ((t_1 == 0) && (len_queue - 1 < MAX_Q))
        {
            len_queue++;
            count_first_in_queue++;
            add_queue_list(&list, 1);
            t_1 = generate_time(TIME_1_0, TIME_1_1);
        }

        double t_next = fmin(t_1, t_OA);
        t_1 -= t_next;
        t_OA -= t_next;
        all_time += t_next;

        if ((count_first_request) % 100 == 0 && count_first_request != 0 && flag == 0)
        {
            printf("���������� ��� ������������ ������ 1-�� ����: %ld\n", count_first_request);
            printf("------------------------------\n");
            printf("������� ������ �������: %ld\n", len_queue);
            printf("������� ������ �������: %lf\n", (double)count_len_queue / (double)events);
            printf("������� ����� ������� � �������: %f �������� ������\n", (double)count_len_queue / (double)events * (double)time_in_OA / (double)event_OA);
            printf("------------------------------\n\n");
            flag = 1;
        }
    }
    stop = clock();
    double time = ((double)stop - (double)start) / CLK_TCK;
    double t_median_OA = (TIME_OA_1 + TIME_OA_0)/2 * MAX_WORK;
    double t_median_1 = (TIME_1_1 + TIME_1_0)/2 * MAX_WORK;
    double expected_time = 0;
    if (t_median_1 > t_median_OA)
        expected_time = t_median_1;
    else
        expected_time = t_median_OA + (TIME_1_1 + TIME_1_0)/2 * count_second_in_queue;
    printf("------------------------------\n");
    printf("����� ����� ������ ���������: %d �������� ������\n", (int)all_time);
    printf("��������� ����� ������ ���������: %d �������� ������\n", (int)expected_time);
    printf("����������� ���������� ������� ������: %.3f%%\n", fabs(all_time - expected_time)/expected_time * 100);
    printf("����� ������ ��������� � ��������: %f ������\n\n", time);
    printf("����� ������� �������� - %.1f �������� ������\n", not_do_OA);
    printf("���������� ������ ������ ������� - %ld, ����� ���� � ������� - %ld\n", count_first_request, count_first_in_queue);
    printf("���������� ������ ������ ������� - %ld, ����� ���� � ������� - %ld\n", count_second_request, count_second_in_queue);
    printf("������� ������ �������: %f �������\n", (double)count_len_queue / (double)events);
    printf("������� ����� ������� � �������: %f �������� ������\n", (double)count_len_queue / (double)events * (double)time_in_OA / (double)event_OA);

    //delete_queue_list(&list);
}


void one_add_count(int n, int precision)
{
    struct queue_array array;
    init_queue_array(&array);

    clock_t start, stop, all_time = 0;
    for (int i = 0; i < n; i++)
        add_queue_array(&array, 1);

    for (int i = 0; i < precision; i++)
    {
        start = clock();
        add_queue_array(&array, 1);
        stop = clock();
        all_time += (stop - start);
        pop_queue_array(&array);
    }
    double time = all_time;
    printf("%.10f               |", time / CLK_TCK / precision);

    struct queue_list allist;
    struct queue_list *list = &allist;
    list->first = (struct leaf*) malloc(sizeof(struct leaf));
    list->last = (struct leaf*) malloc(sizeof(struct leaf));
    list->first->next = list->last;
    list->first->value = 0;
    list->last->next = NULL;
    list->last->value = 0;

    list->size = 0;
    //init_queue_list(&list);

    start = 0, stop = 0, all_time = 0;

    for (int i = 0; i < n; i++)
        add_queue_list(&list, 1);

    for (int i = 0; i < precision; i++)
    {
        start = clock();
        add_queue_list(&list, 1);
        stop = clock();
        all_time += (stop - start);
        pop_queue_list(&list);
    }
    time = all_time;
    printf("%.10f\n", time / CLK_TCK / precision);
}


void one_pop_count(int n, int precision)
{
    struct queue_array array;
    init_queue_array(&array);

    clock_t start, stop, all_time = 0;
    for (int i = 0; i < n; i++)
        add_queue_array(&array, 1);

    for (int i = 0; i < precision; i++)
    {
        start = clock();
        pop_queue_array(&array);
        stop = clock();
        all_time += (stop - start);
        add_queue_array(&array, 1);
    }
    double time = all_time;
    printf("%.10f               |", time / CLK_TCK / precision);

    struct queue_list allist;
    struct queue_list *list = &allist;
    list->first = (struct leaf*) malloc(sizeof(struct leaf));
    list->last = (struct leaf*) malloc(sizeof(struct leaf));
    list->first->next = list->last;
    list->first->value = 0;
    list->last->next = NULL;
    list->last->value = 0;

    list->size = 0;
    //init_queue_list(&list);

    start = 0; stop = 0; all_time = 0, time = 0;

    for (int i = 0; i < n; i++)
        add_queue_list(&list, 1);

    for (int i = 0; i < precision; i++)
    {
        start = clock();
        pop_queue_list(&list);
        stop = clock();
        all_time += (stop - start);
        add_queue_list(&list, 1);
    }
    time = all_time;
    printf("%.10f\n", 2 * time / CLK_TCK / precision);
}

void count_time()
{
    int n = 50, precision = 5000000;
    printf("���������� �������� � �������");
    printf("\n---------------------------------------\n");
    printf("���������� ���������   |������� � ���� �������     |������� � ���� �������� ������\n");
    printf("%d                     |", n);
    one_add_count(n, precision);
    n = 100;
    precision = 5000000;
    printf("%d                    |", n);
    one_add_count(n, precision);
    n = 500;
    precision = 1000000;
    printf("%d                    |", n);
    one_add_count(n, precision);
    n = 1000;
    precision = 500000;
    printf("%d                   |", n);
    one_add_count(n, precision);
    n = 5000;
    precision = 100000;
    printf("%d                   |", n);
    one_add_count(n, precision);
    n = 10000;
    precision = 500000;
    printf("%d                  |", n);
    one_add_count(n, precision);
    printf("-----------------------------------------\n");
    printf("�������� �������� �� �������");
    printf("\n---------------------------------------\n");
    printf("���������� ���������   |������� � ���� �������     |������� � ���� �������� ������\n");
    n = 50;
    precision = 5000000;
    printf("%d                     |", n);
    one_pop_count(n, precision);
    n = 100;
    precision = 5000000;
    printf("%d                    |", n);
    one_pop_count(n, precision);
    n = 500;
    precision = 1000000;
    printf("%d                    |", n);
    one_pop_count(n, precision);
    n = 1000;
    precision = 500000;
    printf("%d                   |", n);
    one_pop_count(n, precision);
    n = 5000;
    precision = 1000000;
    printf("%d                   |", n);
    one_pop_count(n, precision);
    n = 10000;
    precision = 1000000;
    printf("%d                  |", n);
    one_pop_count(n, precision);
    printf("-----------------------------------------\n");
}

void print_menu_play()
{
    printf("------------------------------------\n");
    printf("1 - �������� ������� � �������\n");
    printf("2 - ����� ������� �� �������\n");
    printf("3 - ������� ������� �� �����\n");
    printf("0 - ����� � ������� ���� (������� ��������)\n");
    printf("�������� �����: ");
}

void process_play_with_queue()
{
    struct queue_list allist;
    struct queue_list *list = &allist;
    list->first = (struct leaf*) malloc(sizeof(struct leaf));
    list->last = (struct leaf*) malloc(sizeof(struct leaf));
    list->first->next = list->last;
    list->first->value = 0;
    list->last->next = NULL;
    list->last->value = 0;
    list->size = 0;

    struct address new_add;
    struct address *address = &new_add;
    address->len_address = 0;

    int len_queue = 0;

    while (1 == 1)
    {
        int choose = 0, res;
        print_menu_play();
        res = input_integer(&choose);
        while ((res == error) || (choose < 0) || (choose > 3))
        {
            printf("\n\n������������ ����! ������� ������: ");
            fflush(stdin);
            res = input_integer(&choose);
        }
        int add_elem, del_elem;
        printf("------------------------------\n");
        switch (choose)
        {
        case 1:
            if (len_queue >= MAX_Q)
            {
                printf("������� ��� �����������!\n");
                break;
            }
            len_queue++;
            printf("������� ����� ����� ��� ���������� � �������: ");
            res = input_integer(&add_elem);
            while (res == error)
            {
                printf("\n\n������������ ����! ������� ������: ");
                fflush(stdin);
                res = input_integer(&add_elem);
            }
            add_queue_list(&list, add_elem);
            for (struct leaf *tmp = list->first->next; tmp != list->last; tmp = tmp->next)
            {
                if (tmp->next == list->last)
                    find_add_in_array(&address, &(tmp->value));
            }
            break;
        case 2:
            if (len_queue <= 0)
            {
                printf("������� ������!\n");
                break;
            }
            len_queue--;
            address->address[address->len_address] = &(list->first->next->value);
            address->len_address++;
            del_elem = pop_queue_list(&list);
            printf("�������� �������: %d\n", del_elem);
            printf("------------------------------------\n");
            printf("����� ��������� �������� �� �������: %p\n", (void *)address->address[address->len_address - 1]);
            printf("------------------------------------\n");
            break;
        case 3:
            printf("---------------------------\n");
            print_queue_list(&list);
            printf("---------------------------\n");
            printf("������������ ������:\n");
            if (list->first)
                for (struct leaf *tmp = list->first->next; tmp != list->last; tmp = tmp->next)
                {
                    if (tmp->next != list->last)
                        printf("%p, ", (void *)(&(tmp->value)));
                    else
                        printf("%p\n", (void *)(&(tmp->value)));
                }
            printf("�������������� ������ ��� �����:\n");
            printf("------------------------------------\n");
            for (int i = 0; i < address->len_address; i++)
                printf("%p\n", (void *)address->address[i]);
            printf("------------------------------------\n");
            break;
        }
        if (choose == 0)
            break;
    }
}

void print_menu(void)
{
    printf("------------------------------------\n");
    printf("1 - ������������� ������� �� �������\n");
    printf("2 - ������������� ������� �� ������� ������\n");
    printf("3 - ��������� ������� ������ ���������\n");
    printf("4 - ������ � �������� � ������ ������\n");
    printf("0 - �����\n");
    printf("�������� ����� ����: ");
}



int process_menu()
{
    int choose = 0, res;
    print_menu();
    res = input_integer(&choose);
    while ((res == error) || (choose < 0) || (choose > 4))
    {
        printf("\n\n������������ ����! ������� ������: ");
        fflush(stdin);
        res = input_integer(&choose);
    }
    switch (choose)
    {
    case 1:
        process_model_array();
        break;
    case 2:
        process_model_list();
        break;
    case 3:
        count_time();
        break;
    case 4:
        process_play_with_queue();
        break;
    }
    return choose;
}

