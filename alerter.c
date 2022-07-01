#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
static int FailureCount = 0;
static int NotFailureCount = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius <= 200)
    {
        return 200;
    }
    else
    {
        return 500;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    
}

void alertInCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

float ConvertToCelcius(float farenheit) 
{
    float celcius = (farenheit - 32) * 5 / 9;
    printf("\nconverted: %.1f celcius.\n",celcius);
    return celcius;
}

int test(float Temperature)
{
    float celcius = ConvertToCelcius(Temperature);
    int FAIL = networkAlertStub(celcius);
    printf("Test case :\n");
    
    if(FAIL == 200)
    {
        //printf("OK: Good condition: Temperature is %.1f celcius.\n", FAIL);
        printf("OK: ALERT: Temperature is %d celcius.\n", FAIL);
         NotFailureCount += 1;
        printf("not FailureCount is %d\n", NotFailureCount);
    }
    else if(FAIL == 500)
    {
        //printf("NOT OK: ALERT: Temperature is %.1f celcius.\n", FAIL);
        printf("NOT OK: ALERT: Temperature is %d celcius.\n", FAIL);
        FailureCount += 1;
        printf("FailureCount is %d\n", FailureCount);
    }
    return FAIL;
}

int main() 
{
    alertInCelcius(400.5);
    alertInCelcius(303.6);

    assert(test(300) == 200);
    assert(test(350) == 200);
    assert(test(800) == 500);
    printf("\n%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
