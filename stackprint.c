void    stackprint(t_stack *head)
{
    t_stack    *temp;

    temp = head;
    while (temp)
    {
        printf("%d", temp->value);
		fflush(stdout);
        write(1, " -> ", 4);
        // write(1, "\n", 1);
        temp = temp->next;
    }
    write(1, "NULL\n", 5);
    // write(1, " _\n", 4);
    // write(1, "a b\n", 4);
}
