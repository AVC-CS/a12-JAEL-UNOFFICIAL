#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int glob1 = 20;
int glob2 = 22;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int glob3;
int glob4;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "Parent variable address: " <<parentAddr << endl;
    // TODO: Print &parentAddr (parameter's own address - child frame)
    cout << "Param address child frame: " << &parentAddr << endl;
    // TODO: Print &childVar (local var address - child frame)
    cout << "Child local var adress: " << &childVar << endl;
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << "Stack grows: " << (parentAddr > &childVar ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 0;

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    int* heap1 = (int*)malloc(1024);
    int* heap2 = (int*)malloc(1024);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    cout << "main() address: " << (void*)&main << endl;
    cout << "func2() address: " << (void*)&checkStack << endl;
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    cout << "Global 1 address: " << &glob1 << " value: " << glob1 << endl;
    cout << "Global 2 address: " << &glob2 << " value: " << glob2 << endl;   
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    cout << "Global 3 address: " << &glob3 << " value: " << glob3 << endl;
    cout << "Global 4 address: " << &glob4 << " value: " << glob4 << endl;   
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"

    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    // ...
    cout << "heap1 address: " << heap1 << endl;
    cout << "heap2 address: " << heap2 << endl;
    cout << "Heap grows: " << (heap2 > heap1 ? "UP" : "DOWN") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "TEXT: " << (void*)&main << endl;     
    cout << "DATA: " << &glob1 << endl; 
    cout << "BSS:  " << &glob3 << endl; 
    cout << "HEAP: " << heap1 << endl; 
    cout << "STK: " << &localVar << endl;  
 
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    // ...

    // TODO: Free all heap allocations
    free(heap1);
    free(heap2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 the TEXT segments is the lowest
 * - Which has the highest?
 STACK segment is the highest
 * - Does stack grow down? How did you verify this?
 Stack grows down parent has a higher address than child variable
 * - Does heap grow up? How did you verify this?
 Heap grows up heap2 is higher than heap1
 * - What is the gap between HEAP and STACK?
 the gap between heap and stack is great due to heap starting low and growing up while stack does the opposite starting high and growing down.
 */
