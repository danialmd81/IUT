#include <threadpool>
using namespace boost::threadpool;
void first_task() {
	for(int i=0; i<100; i++)
		printf("in first task\n");
}
void second_task() {
	for(int i=0; i<100; i++)
		printf("in second task\n");
}
void third_task() {
	for(int i=0; i<100; i++)
		printf("in third task\n");
}
void fourth_task() {
	for(int i=0; i<100; i++)
		printf("in fourth task\n");
}
main(){
	// Create a thread pool.
         pool tp(2);
       //Add some tasks to the pool.
      tp.schedule(&first_task);
      tp.schedule(&second_task);
      tp.schedule(&third_task);
      tp.schedule(&fourth_task);
}

