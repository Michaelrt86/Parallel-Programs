#include <iostream>
#include <omp.h>

int main() {
    omp_set_num_threads(4); // Set the number of threads (optional)

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        
        #pragma omp critical // Prevents jumbled output
        std::cout << "Hello from thread " << thread_id << std::endl;
    }

    return 0;
}
