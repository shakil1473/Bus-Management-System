printf("1.Add bus \n2. delete\n3. ");
    printf("Choice(): ");
x:
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        add_bus();
        break;
    case 2:
        del_bus();
        break;
    default:
        goto x;
    }
}
