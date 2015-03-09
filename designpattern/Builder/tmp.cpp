#include <list>
#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <algorithm>
#include <iostream>
// Task
class Task : private boost::noncopyable, public boost::enable_shared_from_this<Task>
{
public:
	Task() : id_(0) {}
	Task(int id) : id_(id) {}
	virtual ~Task() {}
	int id() const { return id_; }
	boost::shared_ptr<Task> ptr() { return shared_from_this(); }
public:
	virtual void run() = 0;
protected:
	int id_;
};
// Task1
class Task1 : public Task
{
public:
	Task1(int id) : Task(id) {}
public:
	virtual void run() { std::cout << "Task1 id: " << id_ << " running" << std::endl; }
};
// Task2
class Task2 : public Task
{
public:
	Task2(int id) : Task(id) {}
public:
	virtual void run() { std::cout << "Task2 id: " << id_ << " running" << std::endl; }
};
// typedefs
typedef boost::shared_ptr<Task> TaskPtr;
typedef std::list<TaskPtr> TaskPtrContainer;
// ptr_contains_predicate
template <typename T>
struct ptr_contains_predicate
{
    ptr_contains_predicate(T* pPtr) : mPtr(pPtr) {}
    template <typename P>
    bool operator()(const P& pPtr) const
    {
        return pPtr.get() == mPtr;
    }
    T* mPtr;
};
// ptr_contains
template <typename T>
ptr_contains_predicate<T> ptr_contains(T* pPtr)
{
    return ptr_contains_predicate<T>(pPtr);
}
// shared_equals_raw
template <typename T> struct shared_equals_raw
{
	shared_equals_raw(T* raw)
		:_raw(raw)
    {}
	bool operator()(const boost::shared_ptr<T>& ptr) const
    {
      return (ptr.get()==_raw);
    }
private:
	T* const _raw;
};
// run task
void run_task(TaskPtr task)
{
//	std::cout << "task id: " << task->id() << std::endl;
	task->run();
}
// print summary
void print_summary(TaskPtrContainer& tasks)
{
	std::cout << "task count " << tasks.size() << std::endl;
}
// application entry
int _tmain(int argc, _TCHAR* argv[])
{
	TaskPtrContainer tasks;
	// test data
	for (int i=0; i<10; i++) {
		if (i % 2 == 0)
			tasks.push_back(TaskPtr(new Task1(i)));
		else
			tasks.push_back(TaskPtr(new Task2(i)));
	}
	// run the tasks.
	std::for_each(tasks.begin(), tasks.end(), run_task);
	print_summary(tasks);  // 10
	//
	// remove by raw pointer
	//
	Task* task = tasks.front().get(); 
	tasks.remove_if(ptr_contains(task));
	print_summary(tasks); // 9
	TaskPtr taskPtr = tasks.front();
	tasks.remove(taskPtr);
	print_summary(tasks); // 8
	// remove by iterator
	task = tasks.front().get();
//	TaskPtrContainer::iterator it = std::find_if(tasks.begin(), tasks.end(), ptr_contains(task));
	// or
	TaskPtrContainer::iterator it = std::find_if(tasks.begin(), tasks.end(), shared_equals_raw<Task>(task));
	if (it != tasks.end()) {
		tasks.erase(it);
	}
	print_summary(tasks);  // 7
	//
	// smart pointer test
	//
	TaskPtr ptr(new Task1(100));
	tasks.push_back(ptr);  
	print_summary(tasks); // 8
	// remove by smart pointer
	tasks.remove(ptr);
	print_summary(tasks); // 7
	// raw pointer test
	Task* task1 = new Task1(200);
	tasks.push_back(TaskPtr(task1));
	print_summary(tasks); // 8
	// donot use in this way. this will cause double delete.
//	tasks.remove(TaskPtr(task1));			// #1 wrong!!! 
	tasks.remove_if(ptr_contains(task1));	// ok
	print_summary(tasks); // 7
	//
	// use enable_shared_from_this
	// 
	Task* task2 = new Task2(300);
	// donot use in this way. not a shared pointer until now.
//	tasks.push_back(task2->ptr());		// #2 wrong!!! 
	tasks.push_back(TaskPtr(task2));	// ok
	print_summary(tasks); // 8
	tasks.remove(task2->ptr());		// #3 correct, problem #1 overcomed
	print_summary(tasks); // 7
	getchar();
	return 0;
}
