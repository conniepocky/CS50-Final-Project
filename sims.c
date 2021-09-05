//includes

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

//vars

static int money;
int startingSalary = 10;
string job = "";
int catordog;
int question;
string q;
int number1;
int number2;
int not_in_friends;
bool ageworks;
int chance_of_death;
static int intelligence;
static int age;
bool dead = false;
string name;
string friends[20] = { NULL };
static int number_of_friends = 0;

// functions

void work(void);
void newgame(void);
void ageup(void);
void buy(void);
void getbio(void);
void socialise(void);
void help(void);

//main

int main(void)
{
    printf("--SIMS 5--\n");
    newgame();

    do {
        q = get_string("$ ");

        if ((strcmp(q, "WORK") == 0) || strcmp(q, "2") == 0)
        {
            work();
        }
        else if ((strcmp(q, "AGEUP") == 0) || strcmp(q, "5") == 0)
        {
            ageup();
        }
        else if ((strcmp(q, "BIO") == 0) || strcmp(q, "1") == 0)
        {
            getbio();
        }
        else if ((strcmp(q, "BUY") == 0) || strcmp(q, "3") == 0)
        {
            buy();
        }
        else if ((strcmp(q, "SOCIALISE") == 0) || strcmp(q, "6") == 0)
        {
            socialise();
        }
        else if ((strcmp(q, "HELP") == 0) || strcmp(q, "7") == 0)
        {
            help();
        }
    }
    while (strcmp(q, "QUIT") != 0 && dead != true);
    printf("--GAME OVER--\n");
}

//help

void help(void)
{
    printf("--HELP--\n");
    printf("If typing in the instructions are not working, please check your spelling or make sure you are using capitals.\n");
    printf("Alternatively, just type the number stated.\n");

    string f = get_string("Do you want me to repeat the instructions? Please either type Y or N. "); 

    if (strcmp(f, "Y") == 0)
    {
        printf("--INSTRUCTIONS--\n");
        printf("1. Type BIO or 1 to see your sims bio. \n");
        printf("2. Type WORK or 2 to go to work/school. \n");
        printf("3. Type BUY or 3 to purchase something. \n");
        printf("4. Type QUIT or 4 to leave the game. \n");
        printf("5. Type AGEUP or 5 to become one year older. \n");
        printf("6. Type SOCIALISE or 6 to get to know people. \n");
        printf("7. Type HELP or 7 to get help and instructions.\n");
    }
    else if (strcmp(f, "N") == 0)
    {
        printf("Going back into game.\n");
    }
    else
    {
        printf("This is most likely why you need help in the game, run HELP again and then type Y or N as instructed.\n");
    }

}

//buy

void buy(void)
{

    printf("--CATALOG--\n");

    printf("1. A phone $1000 \n2. TV $2000 \n3. Waffle $3 \n4. Book $1 \n");
    printf("5. House $1000000\n6. McDonalds Meal $15 \n7. Car $50000\n8. A Computer $1000\n9. A pet $35\n10. An X-Box $500\n");

    int purchase = get_int("What do you want to buy? Choose from our amazing catalog! ");

    if (purchase == 1)
    {
        if (money >= 1000)
        {
            printf("Yayyyy! You bought an ePhone! \n");
            money -= 1000;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    }
    else if (purchase == 2)
    {
        if (money >= 2000)
        {
            printf("Finally! You can watch your favourite movies on the TV!\n");
            money -= 2000;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    }
    else if (purchase == 3) {

        if (money >= 3)
        {
            printf("YAYYYY! WAFFLES!!!!!!!\n");
            money -= 3;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    } else if (purchase == 4)
    {
        if (money >= 1)
        {
            printf("You bought a book!\n");
            money -= 1;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    }
    else if (purchase == 5)
    {
        if (money >= 1000000)
        {
            printf("Yaaaay! Now you have your own house!!!\n");
            money -= 1000000;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    }
    else if (purchase == 6)
    {
        if (money >= 15)
        {
            printf("Yummy! This fancy dinner is great! I love the McFlurry!\n");
            money -= 15;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    } else if (purchase == 7)
    {
        if (money >= 50000)
        {
            printf("Great! You got a car.\n");
            money -= 50000;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    } else if (purchase == 8)
    {
        if (money >= 1000)
        {
            printf("You now have a computer.\n");
            money -= 1000;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    } else if (purchase == 9)
    {
        if (money >= 35)
        {
            catordog = get_int("Cat or dog? (1 or 2) ");
            if (catordog == 1)
            {
                printf("You got a cat!\n");
            }
            else if (catordog == 2)
            {
                printf("You got a dog!\n");
            }
            money -= 35;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    } else if (purchase == 10)
    {
        if (money >= 500)
        {
            printf("Nice! You got an X-Box.\n");
            money -= 500;
        }
        else
        {
            printf("You do not have enough money for this item. You only have $%i.\n", money);
        }
    }
    else
    {
        printf("That is not in our catalog. Please try again and type one of the numbers beside the name of the item.\nE.G For The Waffle type 3 \n");
    }
}

//work and school

void work(void)
{

    if (strcmp(job, "school") == 0)
    {
        printf("--SCHOOL--\n");

        srand(time(NULL));
        number1 = rand() % 10;

        number2 = rand() % 10;
        number2 = round(number2 / 2) + 1;

        question = get_int("What's %d + %d ?", number1, number2);

        if (question == number1 + number2)
        {
            printf("Correct!\n");
            intelligence += rand() % 15;
            printf("You were at school for 6 hours. While at school you reached %i intelligence.\n", intelligence);
        }
        else
        {
            printf("Incorrect.\n");
            printf("You were at school for 6 hours. However while at school you didn't become any smarter.\n");
        }

    }
    else
    {
        printf("--WORK--\n");

        srand(time(NULL));
        int moneyMade = rand() % startingSalary;
        srand(time(NULL));
        int hours = rand() % 2 + 5;

        printf("You went to work for %i hours. While at work you earned $%i.\n", hours, moneyMade);

        money += moneyMade;

        startingSalary++;
    }
}

//ageing

void ageup(void)
{
    age += 1;

    printf("--HAPPY BIRTHDAY! YOU ARE NOW %i YEAR'S OLD--\n", age);

    if (age == 18 )
    {
        printf("You can now get a job!\n");
        job = get_string("What job do you want to have? ");
    }
    else if (age > 18 && (strcmp(job, "school") == 0))
    {
        if (age >= 23)
        {
            job = get_string("You have completed all education and now you can get a job, what job do you want?");
        }
        else
        {
            job = get_string("Do you want to stop studying and get a job now? (Y or N). ");
            if (strcmp(job, "Y") == 0)
            {
                job = get_string("What job do you want to have? ");
            }
            else
            {
                job = "school";
            }
        }
    }

    if (age >= 70)
    {
        srand(time(NULL));
        chance_of_death = rand() % 11;
    }

    if (age >= 120)
    {
        printf("--------------------------\n");
        printf("YOU DIED AGE %i OF OLD AGE\n", age);
        dead = true;
    }
    else if (age >= 90 && chance_of_death == 2)
    {
        printf("--------------------------\n");
        printf("YOU DIED AGE %i OF OLD AGE\n", age);
        dead = true;
    }
}

//socialise

void socialise(void)
{
    printf("--SOCIALISE--\n");
    string f = get_string("Do you want to talk to one of your current friends (1) or make new friends (2) ? ");
    not_in_friends = 0;

    if (strcmp(f, "1") == 0)
    {
        string name_of_friend = get_string("Which friend?");

        for (int i = 0; i <= number_of_friends-1; i++)
        {
            if (strcmp(friends[i], name_of_friend) == 0)
            {
                printf("You spoke to %s and had a nice conversation.\n", name_of_friend);
                i = number_of_friends;
            }
            else
            {
                not_in_friends ++;
            }
        }
        if (not_in_friends == number_of_friends)
        {
            printf("You don't know anyone called %s. \n", name_of_friend);
        }

    }
    else if (strcmp(f, "2") == 0)
    {
        string e = get_string("Please choose a name: ");
        bool alreadyfriends = false;

        for(int i = 0; i < number_of_friends; i++)
        {
            if(strcmp(friends[i], e) == 0)
            {
                printf("You are already friends with this person!\n");
                alreadyfriends = true;
            }
        }

        if (alreadyfriends == false)
        {
            friends[number_of_friends] = malloc(strlen(e) + 1);
            strcpy(friends[number_of_friends], e);

            printf("You became friends with %s!\n", e);

            number_of_friends += 1;

        }
    }
    else
    {
        printf("Please try again and say either 1 or 2.\n");
    }
}

//newgame

void newgame(void)
{

    name = get_string("What is your name? ");
    ageworks = false;

    while (ageworks != true) //make sure age is valid and not too old or young (e.g not 2485754834 or -4587458)
    {
        age = get_int("How old are you? ");
        if (age >= 120)
        {
            printf("Erm sorry your a bit too old, try a lower age.\n");
        }
        else if (age <= 0)
        {
            printf("Sorry too young, try a higher age.\n");
        }
        else if(age >= 18 && age <= 23) //getting job or staying in school
        {
            job = get_string("Do you want to go to school for a bit longer? If you say no then you will have to get a job. (Y or N). ");
            if (strcmp(job, "Y") == 0)
            {
                job = "school";
            }
            else if (strcmp(job, "N") == 0)
            {
                job = get_string("What job do you want? ");
            }
            ageworks = true;
        }
        else if (age >= 18)
        {
            job = get_string("What job do you want?");
            ageworks = true;
        }
        else
        {
            job = "school";
            ageworks = true;
        }
    }

    printf("\n");

    // instructions

    printf("--INSTRUCTIONS--\n");
    printf("1. Type BIO or 1 to see your sims bio. \n");
    printf("2. Type WORK or 2 to go to work/school. \n");
    printf("3. Type BUY or 3 to purchase something. \n");
    printf("4. Type QUIT or 4 to leave the game. \n");
    printf("5. Type AGEUP or 5 to become one year older. \n");
    printf("6. Type SOCIALISE or 6 to get to know people. \n");
    printf("7. Type HELP or 7 to get help and instructions. \n");
}

//get bio

void getbio(void)
{
    printf("NAME: %s \n", name);
    printf("AGE: %i \n", age);
    printf("MONEY: %i \n", money);
    printf("FRIENDS %i \n", number_of_friends);
    printf("INTELLIGENCE: %i\n", intelligence);
}