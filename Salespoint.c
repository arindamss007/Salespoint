#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct offer
{
    char name[30];
    int id;
    char details[100];
    struct offer *next;
};
struct coupon
{
    int id;
    char details[100];
    //Expairy date
    int date;
    int month;
    int year;
    struct coupon *next;
};

struct product
{
    char name[35];
    int price;
    char details[100];
    struct product *next_node;
};

struct catagory
{
    char type[15];
    int catagory_number;
    struct product *start_product_next;
    struct catagory *next;
};

struct catagory *start = NULL; //For catagory and products list main starting parameter.
struct offer *soff; //For offer or offer list starting parameter.
struct coupon *coup; //For Coupon list starting parameter.


//Used in main function
struct catagory *salepoint(struct catagory *);
struct offer *offerZONE(struct offer *);
struct coupon *couponstore(struct coupon *);
struct catagory *administrator(struct catagory *);



//Global Sub-functions of Administrator
struct catagory *create_catagory_list(struct catagory *);
struct catagory *create_product_list(struct catagory *);
struct catagory *delete_product(struct catagory *);
struct catagory *delete_product_list(struct catagory *);
struct catagory *delete_catagory(struct catagory *);
struct catagory *delete_catagory_list(struct catagory *);
struct catagory *display_catagory(struct catagory *);
struct catagory *display_product(struct catagory *);
struct product *new_product(struct product *);
struct product *display_pdr(struct product *);
struct product *del_pdr_beg(struct product *);
struct offer *cerate_offer(struct offer *);
struct offer *delete_offer(struct offer *);
struct offer *display_offer(struct offer *);
struct product *new_product(struct product *);

//under sub-function of delete catagory
struct catagory *delete_from_front(struct catagory *);
struct catagory *delete_from_end(struct catagory *);
struct catagory *delete_from_middle(struct catagory *);

//under coupon store sub functions
struct coupon *view_free_coupon(struct coupon *);
struct coupon *admin(struct coupon *);

int pass;

//under offer-zone sub function
struct offer *view_product_offers(struct offer *);
struct offer *admin_panel(struct offer *);
struct offer *create_offer(struct offer *);
struct offer *delete_offer(struct offer *);
struct offer *display_offer(struct offer *);

int main()
{
    int option, i;
    printf("\n\nHi Sir, Please Set Your Password [Numbers Only] :\t");
    scanf("%d", &pass);

    while(option != 5)
    {
        printf("\033[0;34m\n\n");
        printf("000000000    000000    000        0000000000  000000000\n");
        printf("00          00    00   000        00       0  00       \n");
        printf("00         00      00  000        00          00       \n");
        printf("000000000  00      00  000        0000000     000000000\n");
        printf("       00  0000000000  000        00                 00\n");
        printf("       00  00      00  000    00  00       0         00\n");
        printf("000000000  00      00  000000000  0000000000  000000000\n");

        printf("\033[0;33m\n");

        printf("00000000   00000000  00000000  000      00 00000000000\n");
        printf("00      0 000    000    00     00 0     00 0    0    0\n");
        printf("00      0 00      00    00     00  0    00      0     \n");
        printf("00      0 0        0    00     00   0   00      0     \n");
        printf("00000000  00      00    00     00    0  00      0     \n");
        printf("00        000    000    00     00     0 00      0     \n");
        printf("00         00000000  000000000 00      000      0     \n\n");

        printf("\033[0;37m");
        printf("[1] SALE POINT \n[2] COUPON STORE\n[3] ADMINISTRATOR\n[4] OFFER ZONE\n[5] EXIT\n\nResponse :\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1 : 
                start = salepoint(start);
                break;
            case 2 :
                coup = couponstore(coup);
                break;
            case 3 :
                printf("\nEnter the password :\t");
                scanf("%d", &i);
                if(i !=pass)
                {
                    printf("\nWrong Password !\n");
                    break;
                }
                else
                {
                    start = administrator(start);
                    break;
                }
                break;
            case 4 :
                soff = offerZONE(soff);


        }
    }
    return 0;
}

struct catagory *administrator(struct catagory *start)
{
    struct catagory *ptr;
    ptr = start;
    int i,option;

    while(option != 9)
    {
        printf("\033[0;33m\n\n");
        printf("  00000000    0000000000     0000        0000  00000000   00         00\n");
        printf("00        00  00       00    0000        0000     00      00 0       00\n");
        printf("00        00  00        00   00   0    0   00     00      00   0     00\n");
        printf("00        00  00         00  00    0  0    00     00      00    0    00\n");
        printf("000000000000  00         00  00     0      00     00      00    0    00\n");
        printf("00        00  00        00   00            00     00      00     0   00\n");
        printf("00        00  00       00    00            00     00      00       0 00\n");  
        printf("00        00  0000000000     00            00  00000000   00         00\n");

        printf("\033[0;34m\n\n");
        printf("00       00   00000000   000000000    00000000\n");      
        printf("00 0   0 00  00      00  00      00   00     0\n");
        printf("00   0   00  0        0  00       00  00000   \n");  
        printf("00       00  0        0  00       00  00000   \n");  
        printf("00       00  00      00  00      00   00     0\n");
        printf("00       00   00000000   000000000    00000000\n\n");

        printf("\033[0;37m");
        printf("[1] Create catagory list\n[2] Create product list\n[3] Delete a product\n[4] Delete the product list\n[5] Delete catagory\n[6] Delete catagory list\n[7] Display Catagory\n[8] Display Product\n[9] Exit\n\nResponse :\t");
        scanf("%d", &option);

        switch(option)
        {
            case 1 : 
                start = create_catagory_list(start);
                printf("\nCatagory list is Created !\n");
                break;
            case 2 :
                start = create_product_list(start);
                printf("\nList has been created !\n");
                break;
            case 3 :
                start = delete_product(start);
                break;
            case 4 :
                start = delete_product_list(start);
                break;
            case 5 :
                start = delete_catagory(start);
                break;
            case 6 :
                start = delete_catagory_list(start);
                break;
            case 7 :
                start = display_catagory(start);
                break;
            case 8 :
                start = display_product(start);
                break;
        }
    }

    return start;
}

struct catagory *create_catagory_list(struct catagory *start)
{
    struct catagory *ptr,*new_catagory;
    ptr = start;
    if(start == NULL)
    {
        start = (struct catagory *)malloc(sizeof(struct catagory));
        ptr = start;
        printf("Enter catagory number [Don't Enter Same numbers] :\t");
        scanf("%d", &ptr->catagory_number);
        printf("Enter the name of product Type or Catagory :\t");
        scanf("%s", &ptr->type);
        ptr->next = NULL;
    }

    else
    {
        while(ptr->next != NULL)
            ptr = ptr ->next;
        new_catagory = (struct catagory *)malloc(sizeof(struct catagory));
        printf("Enter catagory number [Don't Enter Same numbers] :\t");
        scanf("%d", &new_catagory->catagory_number);
        printf("Enter the name of product Type or Catagory :\t");
        scanf("%s", &new_catagory->type);
        ptr->next = new_catagory;
    }
    return start;
}

struct product *new_product(struct product *prod)
{
    prod = (struct product *)malloc(sizeof(struct product));
    printf("Enter the name of the product :\t");
    scanf("%s", &prod->name);
    printf("Enter the price of the product :\t");
    scanf("%d", &prod->price);
    printf("Enter the details of the product :\t");
    scanf("%s", &prod->details);
    return prod;
}

struct catagory *create_product_list(struct catagory *start)
{
    int n;
    struct product *stpdr, *temp, *prod;
    struct catagory *ptr;
    ptr = start;
    printf("Enter The catagory number :\t");
    scanf("%d", &n);
    while(ptr->catagory_number != n)
    {
        if(ptr == NULL)
        {
            printf("Invalid Catagory number !\n");
            exit(0);
        }
        ptr = ptr->next;
    } 
    stpdr = ptr->start_product_next;

    if(stpdr == NULL)
    {
        prod = new_product(prod);
        ptr->start_product_next = prod;
    }
    else
    {
        while(stpdr->next_node != NULL)
        {
            stpdr = stpdr->next_node;
        }
        prod = new_product(prod);
        stpdr->next_node = prod;
    }

    return start;
}


struct catagory *delete_product(struct catagory *start)
{
    struct catagory *ptr;
    struct product *stpdr, *preptr;
    int a;
    ptr = start;
    printf("\nEnter the Catagory Number :\t");
    scanf("%d", &a);

    while(ptr->catagory_number != a)
    {
        ptr = ptr->next;
    }
    stpdr = ptr->start_product_next;
    if(stpdr->next_node == NULL)
    {
    	 free(stpdr);
   	 stpdr = NULL;
    }
    else
    {
	    while(stpdr->next_node != NULL)
	    {
		    preptr = stpdr;
		    stpdr = stpdr->next_node;
	    }
	    free(stpdr);
	    preptr->next_node = NULL;
    }
	
    return start;
}
struct product *del_pdr_beg(struct product *stpdr)
{
    struct product *ptr;
    ptr = stpdr;
    stpdr = stpdr->next_node;
    free(ptr);
    ptr = NULL;
    return stpdr;
}

struct catagory *delete_product_list(struct catagory *start)
{
    struct catagory *ptr;
    struct product *stpdr;
    int a;
    ptr = start;
    printf("\nEnter the Catagory Number :\t");
    scanf("%d", &a);
    while(ptr->catagory_number != a)
    {
        ptr = ptr->next;
    }
    stpdr = ptr->start_product_next;
    while(stpdr != NULL)
    {
        stpdr = del_pdr_beg(stpdr);
        stpdr = stpdr->next_node;
    }
    ptr->start_product_next = NULL;

    return start;
}

struct catagory *delete_catagory(struct catagory *start)
{
    int option;
    while(option != 4)
    {
        printf("[1] Delete from front\n[2] Delete from end\n[3] Delete from middle\n[4] Exit\n\nResponse:\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1: start = delete_from_front(start);
                break;
            case 2: start = delete_from_end(start);
                break;
            case 3: start = delete_from_middle(start);
                break;
        }
    }
    return start;
}

struct catagory *delete_from_front(struct catagory *start)
{
    struct catagory *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    ptr=NULL;
    return start;
}

struct catagory *delete_from_end(struct catagory *start)
{
    struct catagory *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    preptr->next = NULL;
    return start;
}

struct catagory *delete_from_middle(struct catagory *start)
{
    struct catagory *ptr, *preptr;
    int a;
    ptr = start;
    printf("Enter the number of catagory type :\t");
    scanf("%d", &a);
    while(ptr->catagory_number != a)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    ptr=NULL;
    return start;
}

struct catagory *delete_catagory_list(struct catagory *start)
{
    int a;
    printf("Are you sure to delete the catagory list ?[Yes = 99/NO = 11]\n\nResponse :\t");
    scanf("%d", &a);
    if(a==99)
    {
        free(start);
        start = NULL;
    }
    return start;
}

struct catagory *display_catagory(struct catagory *start)
{
    struct catagory *ptr;
    ptr = start;
    if(ptr == NULL)
    {
        printf("NO, Catagorys Available !");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("\n(%d)\t", ptr->catagory_number);
            printf("%s\n", ptr->type);
            ptr = ptr->next;
        }
    }
    return start;
}

struct product *display_pdr(struct product *pdr)
{
    struct product *stpdr;
    stpdr = pdr;
    int i=0;
    do
    {
        ++i;
        printf("\n(%d)\t",i);
        puts(stpdr->name);
        printf("price :\t%d/-\n", stpdr->price);
        printf("Details :\n\n");
        puts(stpdr->details);
        printf("\n\n");
        stpdr = stpdr->next_node;
    }while(stpdr != NULL);
    return pdr;
}
struct catagory *display_product(struct catagory *start)
{
    struct catagory *ptr, *temp;
    struct product *pdr;
    int a,i=0;
    ptr = start;
    printf("Enter Catagory Number :\t");
    scanf("%d", &a);

    while(ptr->next != NULL)
    {
        if(ptr->catagory_number == a)
        {
            pdr = ptr->start_product_next;
            temp = start;
        }
        ptr = ptr->next;
    }

    if(temp == NULL)
    {
        printf("\nSorry, You entered a invalid Catagory Number !\n");
    }
    else
    {
        if(pdr == NULL)
        {
            printf("\nNo, Products Are Here !\n");
        }
        else
        {
            pdr = display_pdr(pdr);
        }
    }

    return start;
}


struct coupon *couponstore(struct coupon *coup)
{
    int option;
    while(option != 3)
    {
        printf("\033[0;34m\n\n");
        printf(" 000000000   000000000    00       00  000000000     000000000    000        00\n");
        printf("00000    0  00        00  00       00  00       00  00        00  00  0      00\n"); 
        printf("000         00        00  00       00  00       00  00        00  00   0     00\n"); 
        printf("00          00        00  00       00  00       00  00        00  00    0    00\n"); 
        printf("000         00        00  00       00  000000000    00        00  00     0   00\n");
        printf("00000    0  00        00  000     000  00           00        00  00      0  00\n");
        printf(" 000000000   0000000000    000000000   00            0000000000   00        000\n");
    
        printf("\033[0;33m\n");

        printf(" 00000000  0000000000   0000000000   00000000      00000000\n");  
        printf("0       0  0   00   0  00        00  00      00    00      \n");  
        printf("0              00      00        00  00      00    00      \n");  
        printf("00000000       00      00        00  000000000     00000   \n");      
        printf("        0      00      00        00  00       00   00      \n");  
        printf("0       0      00      00        00  00        00  00      \n");  
        printf("00000000      0000      0000000000   00        00  00000000\n\n");
        printf("\033[0;37m");
        printf("[1] View free Coupons\n[2] Admin\n[3] Exit\n\nResponse :\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1 :
                coup = view_free_coupon(coup);
                break;
            case 2 :
                coup = admin(coup);
                break;
            case 3 :
                break;
        }
    }
    return coup;
}

struct coupon *view_free_coupon(struct coupon *coup)
{
    printf("\033[0;34m\n\n");
    printf(" 000000000   000000000    00       00  000000000     000000000    000        00\n");
    printf("00000    0  00        00  00       00  00       00  00        00  00  0      00\n"); 
    printf("000         00        00  00       00  00       00  00        00  00   0     00\n"); 
    printf("00          00        00  00       00  00       00  00        00  00    0    00\n"); 
    printf("000         00        00  00       00  000000000    00        00  00     0   00\n");
    printf("00000    0  00        00  000     000  00           00        00  00      0  00\n");
    printf(" 000000000   0000000000    000000000   00            0000000000   00        000\n");
    
    printf("\033[0;33m\n");

    printf(" 00000000  0000000000   0000000000   00000000      00000000\n");  
    printf("0       0  0   00   0  00        00  00      00    00      \n");  
    printf("0              00      00        00  00      00    00      \n");  
    printf("00000000       00      00        00  000000000     00000   \n");      
    printf("        0      00      00        00  00       00   00      \n");  
    printf("0       0      00      00        00  00        00  00      \n");  
    printf("00000000      0000      0000000000   00        00  00000000\n\n");

    struct coupon *ptr, *new_node;
    ptr = coup;
    if(ptr == NULL)
    {
        printf("\nSorry, No Coupons Available !\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("\n\nThe Coupon Id is :\t%d", ptr->id);
            printf("\n\nDetails :\n\n%s\n\n",ptr->details);
            printf("Expairy date : %d / %d / %d \n\n\n",ptr->date,ptr->month,ptr->year);
            ptr = ptr->next;
        }
    }
    return coup;
}

struct coupon *admin(struct coupon *coup)
{
    struct coupon *ptr, *new_node;
    int option;
    int i;
    ptr = coup;
        printf("\033[0;33m\n\n");
        printf("  00000000    0000000000     0000        0000  00000000   00         00\n");
        printf("00        00  00       00    0000        0000     00      00 0       00\n");
        printf("00        00  00        00   00   0    0   00     00      00   0     00\n");
        printf("00        00  00         00  00    0  0    00     00      00    0    00\n");
        printf("000000000000  00         00  00     0      00     00      00    0    00\n");
        printf("00        00  00        00   00            00     00      00     0   00\n");
        printf("00        00  00       00    00            00     00      00       0 00\n");  
        printf("00        00  0000000000     00            00  00000000   00         00\n");

        printf("\033[0;34m\n\n");
        printf("00       00   00000000   000000000    00000000\n");      
        printf("00 0   0 00  00      00  00      00   00     0\n");
        printf("00   0   00  0        0  00       00  00000   \n");  
        printf("00       00  0        0  00       00  00000   \n");  
        printf("00       00  00      00  00      00   00     0\n");
        printf("00       00   00000000   000000000    00000000\n\n");   

        printf("\033[0;37m");
    while(i != 99)
    {
        printf("Enter 99 for go back !\n");
        printf("Enter the password :\t");
        scanf("%d", &i);
        if(i != pass)
        {
            printf("\nWrong password, try again !\n");
        }
        else
        {
            printf("\nWelcome, sir !\n\n");
            i=99;
            while(option != 4)
            {
                printf("\033[0;34m\n\n");
                printf(" 000000000   000000000    00       00  000000000     000000000    000        00\n");
                printf("00000    0  00        00  00       00  00       00  00        00  00  0      00\n"); 
                printf("000         00        00  00       00  00       00  00        00  00   0     00\n"); 
                printf("00          00        00  00       00  00       00  00        00  00    0    00\n"); 
                printf("000         00        00  00       00  000000000    00        00  00     0   00\n");
                printf("00000    0  00        00  000     000  00           00        00  00      0  00\n");
                printf(" 000000000   0000000000    000000000   00            0000000000   00        000\n");
    
                printf("\033[0;33m\n");

                printf(" 00000000  0000000000   0000000000   00000000      00000000\n");  
                printf("0       0  0   00   0  00        00  00      00    00      \n");  
                printf("0              00      00        00  00      00    00      \n");  
                printf("00000000       00      00        00  000000000     00000   \n");      
                printf("        0      00      00        00  00       00   00      \n");  
                printf("0       0      00      00        00  00        00  00      \n");  
                printf("00000000      0000      0000000000   00        00  00000000\n\n");

                printf("\033[0;37m");
                printf("[1] Create a coupon\n[2] Delete coupon\n[3] Display\n[4] Exit\nResponse :\t");
                scanf("%d", &option);
                if(option == 1)
                {
                    if(coup == NULL)
                    {
                        new_node = (struct coupon *)malloc(sizeof(struct coupon));
                        coup = new_node;
                        ptr = coup;
                        printf("Enter the coupon id :\t");
                        scanf("%d", &ptr->id);
                        printf("Enter Details of the coupon :\t");
                        scanf("%s", &ptr->details);
                        printf("Enter The Expairy date :\n\n");
                        printf("Date :\t");
                        scanf("%d", &ptr->date);
                        printf("Month :\t");
                        scanf("%d", &ptr->month);
                        printf("Year :\t");
                        scanf("%d", &ptr->year);
                    }
                    else
                    {
                        while(ptr->next != NULL)
                            ptr = ptr->next;
                        new_node = (struct coupon *)malloc(sizeof(struct coupon));
                        ptr->next = new_node;
                        printf("Enter the coupon id :\t");
                        scanf("%d", &ptr->id);
                        printf("Enter Details of the coupon :\t");
                        scanf("%s", &ptr->details);
                        printf("Enter The Expairy date :\n\n");
                        printf("Date :\t");
                        scanf("%d", &ptr->date);
                        printf("Month :\t");
                        scanf("%d", &ptr->month);
                        printf("Year :\t");
                        scanf("%d", &ptr->year);
                    }
                }
                else if(option == 2)
                {
                    if(coup == NULL)
                    {
                        printf("UNDERFLOW !");
                        break;
                    }
                    else
                    {
                        while(ptr->next != NULL)
                            ptr = ptr->next;
                        free(ptr);
                        ptr = NULL;
                    }
                }
                else if(option == 3)
                {
                    if(coup == NULL)
                    {
                        printf("Sorry, No Coupons Available !");
                    }
                    else
                    {
                        while(ptr != NULL)
                        {
                            printf("\n\nThe Coupon Id is :\t%d", ptr->id);
                            printf("\n\nDetails :\n\n%s\n\n",ptr->details);
                            printf("Expairy date : %d / %d / %d \n\n\n",ptr->date,ptr->month,ptr->year);
                            ptr = ptr->next;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
    
    }
    return coup;
}


struct offer *offerZONE(struct offer *soff)
{
    int option;
    while(option != 3)
    {
        printf("\033[0;33m\n");
        printf(" 00000000   0000000000  0000000000  0000000000  0000000000   \n");   
        printf("000    000  00          00          00          00        00 \n");   
        printf("00      00  00          00          00          00        00 \n");   
        printf("0        0  00          00          000000      00        00 \n");   
        printf("0        0  0000000     0000000     000000      0000000000   \n");       
        printf("00      00  00          00          00          00        00 \n");   
        printf("000    000  00          00          00          00         00\n");
        printf(" 00000000   00          00          0000000000  00         00\n");

        printf("\033[0;34m\n");

        printf("000000000   0000000   000     00  00000000\n");
        printf("       0   00     00  00 0    00  00       \n");   
        printf("    0      0       0  00   0  00  000000   \n");   
        printf(" 0         00     00  00    0 00  00       \n");   
        printf("000000000   0000000   00     000  00000000\n\n");
        printf("\033[0;37m");
        printf("[1] VIEW PRODUCTS OFFERS\n[2] ADMIN PANEL\n[3] EXIT\n\nResponse :\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1 :
                soff = view_product_offers(soff);
                break;
            case 2 :
                soff = admin_panel(soff);
                break;
        }
    }
}
struct offer *create_offer(struct offer *soff)
{
    struct offer *ptr,*new_node;
    ptr = soff;
    if(soff == NULL)
    {
        new_node = (struct offer *)malloc(sizeof(struct offer));
        soff = new_node;
        ptr = soff;
        printf("Enter the offer id :\t");
        scanf("%d", &ptr->id);
        printf("Enter the offer name :\t");
        scanf("%s", &ptr->name);
        printf("Enter the offer details :\t");
        scanf("%s", &ptr->details);
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new_node = (struct offer *)malloc(sizeof(struct offer));
        ptr->next = new_node;
        printf("Enter the offer name :\t");
        scanf("%s", &new_node->name);
        printf("Enter the offer id :\t");
        scanf("%d", &new_node->id);
        printf("Enter the offer details :\t");
        scanf("%s", &new_node->details);
    }
    return soff;
}
struct offer *delete_offer(struct offer *soff)
{
    struct offer *ptr;
    ptr = soff;
    if(soff == NULL)
    {
        printf("\nUnder Flow !\n");
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr);
        printf("One offer is deleted from the list !\n");
    }
    return soff;
}
struct offer *display_offer(struct offer *soff)
{
    struct offer *ptr;
    ptr = soff;
    if(soff == NULL)
    {
        printf("NO offers here !");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("Offer Name :\t%s\n", ptr->name);
            printf("ID number :\t%d\n", ptr->id);
            printf("Details :\n\n%s", ptr->details);
            ptr = ptr->next;
        }
    }
    return soff;
}

struct offer *view_product_offers(struct offer *soff)
{
    struct offer *ptr;
    ptr = soff;
    if(soff == NULL)
    {
        printf("Sorry, We have not any offers for you !");
    }
    else
    {
        while(ptr->next != NULL)
        {
            printf("Offer Name :\t%s\n", ptr->name);
            printf("ID number :\t%d\n", ptr->id);
            printf("Details :\n\n%s", ptr->details);
            ptr = ptr->next;
        }
    }
    return soff;
}

struct offer *admin_panel(struct offer *soff)
{
    int option, i;
    struct offer *ptr,*new_node;
        printf("\033[0;33m\n\n");
        printf("  00000000    0000000000     0000        0000  00000000   00         00\n");
        printf("00        00  00       00    0000        0000     00      00 0       00\n");
        printf("00        00  00        00   00   0    0   00     00      00   0     00\n");
        printf("00        00  00         00  00    0  0    00     00      00    0    00\n");
        printf("000000000000  00         00  00     0      00     00      00    0    00\n");
        printf("00        00  00        00   00            00     00      00     0   00\n");
        printf("00        00  00       00    00            00     00      00       0 00\n");  
        printf("00        00  0000000000     00            00  00000000   00         00\n");

        printf("\033[0;34m\n\n");
        printf("00       00   00000000   000000000    00000000\n");      
        printf("00 0   0 00  00      00  00      00   00     0\n");
        printf("00   0   00  0        0  00       00  00000   \n");  
        printf("00       00  0        0  00       00  00000   \n");  
        printf("00       00  00      00  00      00   00     0\n");
        printf("00       00   00000000   000000000    00000000\n\n");
        printf("\033[0;37m");
    while(i != 99)
    {
        printf("Enter 99 for go back !\n");
        printf("Enter the password :\t");
        scanf("%d", &i);
        if(i != pass)
        {
            printf("\nWrong password, try again !\n");
        }
        else
        {
            printf("\nWelcome, sir !\n\n");
            i=99;
            while(option != 4)
            {
                printf("\033[0;33m\n\n");
                printf("  00000000    0000000000     0000        0000  00000000   00         00\n");
                printf("00        00  00       00    0000        0000     00      00 0       00\n");
                printf("00        00  00        00   00   0    0   00     00      00   0     00\n");
                printf("00        00  00         00  00    0  0    00     00      00    0    00\n");
                printf("000000000000  00         00  00     0      00     00      00    0    00\n");
                printf("00        00  00        00   00            00     00      00     0   00\n");
                printf("00        00  00       00    00            00     00      00       0 00\n");  
                printf("00        00  0000000000     00            00  00000000   00         00\n");

                printf("\033[0;34m\n\n");
                printf("00       00   00000000   000000000    00000000\n");      
                printf("00 0   0 00  00      00  00      00   00     0\n");
                printf("00   0   00  0        0  00       00  00000   \n");  
                printf("00       00  0        0  00       00  00000   \n");  
                printf("00       00  00      00  00      00   00     0\n");
                printf("00       00   00000000   000000000    00000000\n\n"); 
                printf("\033[0;37m");
                printf("[1] CREATE OFFER\n[2] DELETE OFFER\n[3] DISPLAY OFFER\n[4] EXIT\n\nResponse :\t");
                scanf("%d", &option);
                switch(option)
                {
                    case 1:
                        soff = create_offer(soff);
                        printf("\nOffer is created !\n");
                        break;
                    case 2 :
                        soff = delete_offer(soff);
                        if(soff != NULL)
                        {
                            printf("\nOne offer is deleted from last !\n");
                        }                        
                        break;
                    case 3 :
                        soff = display_offer(soff);
                        break;
                }
            }
        }
    }
    
    return soff;
}

struct catagory *salepoint(struct catagory *start)
{
    struct catagory *ptr;
    ptr=start;
    int option;
    while(option !=3)
    {
        printf("\033[0;34m\n");
        printf("000000000    000000    000        0000000000  000000000\n");
        printf("00          00    00   000        00       0  00       \n");
        printf("00         00      00  000        00          00       \n");
        printf("000000000  00      00  000        0000000     000000000\n");
        printf("       00  0000000000  000        00                 00\n");
        printf("       00  00      00  000    00  00       0         00\n");
        printf("000000000  00      00  000000000  0000000000  000000000\n");

        printf("\033[0;33m\n");

        printf("00000000   00000000  00000000  000      00 00000000000\n");
        printf("00      0 000    000    00     00 0     00 0    0    0\n");
        printf("00      0 00      00    00     00  0    00      0     \n");
        printf("00      0 0        0    00     00   0   00      0     \n");
        printf("00000000  00      00    00     00    0  00      0     \n");
        printf("00        000    000    00     00     0 00      0     \n");
        printf("00         00000000  000000000 00      000      0     \n\n");
        printf("\n\n");
        printf("\033[0;37m");

        printf("[1] VIEW PRODUCT CATAGORYS\n[2] VIEW PRODUCTS\n[3] EXIT\n\nResponse :\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1 :
                start = display_catagory(start);
                break;
            case 2 :
                if(start== NULL)
                {
                    printf("\nNo, Products Available Here !\n");
                }
                else
                {
                    if(ptr->start_product_next == NULL)
                    {
                        printf("\nNo, Products Available Here !\n");
                    }
                    else
                    {
                        start = display_product(start);
                    }
                }
                break;
        }
    }
    return start;
}
