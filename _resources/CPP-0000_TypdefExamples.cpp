#include <math.h>
#include <stdint.h> // gnu compiler extension of C language data type for int
// #include <iostream>
// 
// using namespace std;
// 
// or
// #include <stdio.h> for C

typedef int Counter; // similar to #define Counter int

// defines a type called Linebuf, which is an array of 81 characters
typedef char Linebuf[81];

typedef struct
{
    int month;
    int day;
    int year;
} Date;

typedef struct
{
    float x;
    float y;
} xyPoint;

// function taking xyPoint type as argument
double distance(xyPoint p1, xyPoint p2);

typedef enum
{
    kRedState = 0,
    kYellowState = 1,
    kGreenState = 2
} tState;

typedef enum
{
    eModel,
    eSupport,
    eExtruderCount
} extruder_number;

typedef enum
{
    eExtruderPresent       = 0x1,
    eExtruderIoEnabled     = 0x2,
    eExtruderCommunicating = 0x4
} extruder_detect_bits;

#if 0
// Example from FreeRTOS: won't compile
/*
 * In line with software engineering best practice, FreeRTOS implements a strict
 * data hiding policy, so the real structures used by FreeRTOS to maintain the
 * state of tasks, queues, semaphores, etc. are not accessible to the application
 * code.  However, if the application writer wants to statically allocate such
 * an object then the size of the object needs to be know.  Dummy structures
 * that are guaranteed to have the same size and alignment requirements of the
 * real objects are used for this purpose.  The dummy list and list item
 * structures below are used for inclusion in such a dummy structure.
 */
struct xSTATIC_LIST_ITEM
{
	TickType_t xDummy1;
	void *pvDummy2[ 4 ];
};
typedef struct xSTATIC_LIST_ITEM StaticListItem_t;
#endif

// example from zephyr project @ zephyr/arch/arm/include/aarch32/cortex_m/tz.h
/**
 *
 * @brief Initial Non-Secure state configuration
 *
 * A convenient struct to include all required Non-Secure
 * state configuration.
 */
typedef struct tz_nonsecure_setup_conf {
	uint32_t msp_ns;
	uint32_t psp_ns;
	uint32_t vtor_ns;
	struct {
		uint32_t npriv:1;
		uint32_t spsel:1;
		uint32_t reserved:30;
	} control_ns;
} tz_nonsecure_setup_conf_t;

int main(void)
{
    Counter attendee, contestant;
    Linebuf text, inputLine; // equivalent to char text[81], inputLine[81];
    // tz_nonsecure_setup_conf abc; error illegal
    struct tz_nonsecure_setup_conf myConfig; // legal, long way
    tz_nonsecure_setup_conf_t myConfig2; // legal
    

    // array containing 100 Date structures
    Date birthdays[100];

    xyPoint origin = {0.0, 0.0}, currentPoint;
    
    // C- only can specify the struct field element in any order using the dot "." 
    // xyPoint distance = {.y=1, .x=3};  //erro if using c++ compiler
}

// calculated the distance between 2 points
double distance(xyPoint p1, xyPoint p2)
{
    double diffx, diffy;
    diffx = p1.x - p2.x;
    diffy = p1.y - p2.y;
    return sqrt(diffx * diffx + diffy * diffy);
}
