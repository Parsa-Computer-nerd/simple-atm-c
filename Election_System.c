#include <stdio.h>
int main()
{
    int numCandidates, Counter, numVoters, numerator, vote, computer, Maxvote, Winner;
    int votes[1000];

    printf("numCandidates: ");
    scanf("%d", &numCandidates);

    for (Counter = 0; Counter <= numCandidates - 1; Counter++)
    {
        votes[Counter] = 0;
    }

    printf("How many people are going to vote? ");
    scanf("%d", &numVoters);

    for (numerator = 1; numerator <= numVoters; numerator++) // حلقه ثبت رای هر یک از رای دهندگان
    {
        printf("Enter your vote 1-%d:", numCandidates);
        scanf("%d", &vote);

        if (vote <= numCandidates && vote >= 1) 
        {
            votes[vote - 1]++; //ثبت هر یک از رای ها
        }
        else
        {
            printf("Invalid vote! Try again.\n");
            numerator--;
        }
    }

    for (computer = 0; computer <= numCandidates - 1; computer++) // نمایش هر کدام از کاندیدها (اندیس آنها + تعداد رای)
    {
        printf("Candidate %d ", computer + 1);
        printf(": %d", votes[computer]);
        printf("\n");
    }

    Maxvote = votes[0];
    Winner = 1;

    for (computer = 1; computer < numCandidates; computer++) // پیدا کردن کاندید برتر ( نمایش اندیس بیشترین کاندیدی که رای دارد + رای آن )
    {
        if (votes[computer] > Maxvote)
        {
            Maxvote = votes[computer];
            Winner = computer + 1;
        }
    }

    printf("Winner is Candidate : %d\n ", Winner);
    printf("votes : %d\n ", Maxvote);

    return 0;
}
