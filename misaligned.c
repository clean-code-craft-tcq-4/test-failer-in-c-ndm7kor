#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
char AlignmentCheck[1000];
char ReferenceAlignmentCheck[1000];

int printColorMap(char *AlignmentCheck) 
{
    int minor = 0;
    int major = 0;
    int pairnum = 0;
    
    for(major=0; major<5; major++)
    {
        for(minor=0; minor<5; minor++)
        {
            pairnum += sprintf(&AlignmentCheck[pairnum], "%d\t|%s\t\t|%s\n",((major * 5 + minor) + 1), (majorColor[major]), (minorColor[minor]));
        }
    }
    printf("Below is the Actual manual color code display which has to be checked for Alignment\n%s\n",AlignmentCheck);
    
    return minor*major;
}

void ReferenceManual_ColorCode(char *ReferenceAlignmentCheck)
{
    int minor = 0;
    int major = 0;
    int pairnum = 0;
    
    for(major=0; major<5; major++)
    {
        for(minor=0; minor<5; minor++)
        {
            pairnum += sprintf(&ReferenceAlignmentCheck[pairnum], "%d\t|%s\t\t|%s\n",((major * 5 + minor) + 1), (majorColor[major]), (minorColor[minor]));
        }
    }
    
    printf("Below is the reference manual color code display\n%s\n",ReferenceAlignmentCheck);
}

void AlignmentCheck_EvaluatingString()
{
    assert(strcmp(&ReferenceAlignmentCheck[0],&AlignmentCheck[0]) == 0);   
    /*int ret = (strcmp(&ReferenceAlignmentCheck[0],&AlignmentCheck[0]) == 0);  
    if(ret == 0)
    printf("yse\n");
    else
    printf("no\n");*/
    
}

int main() 
{
    int result = printColorMap(AlignmentCheck);
    ReferenceManual_ColorCode(ReferenceAlignmentCheck);
    assert(result == 25);
    AlignmentCheck_EvaluatingString();
    printf("All is well (maybe!)\n");
    return 0;
}
