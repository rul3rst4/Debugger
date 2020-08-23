// This class will offer a way to manage things related to the system.
// Async operations, Tasks, etc...
//

#include <atomic>
#include <thread>
#include <vector>

static std::vector<std::thread> worker_threads;

class System
{
public:
  class Task {
  public:
    virtual void run() = 0;

    virtual ~Task() = default;

    bool complete() const
    {
      return complete_;
    }

    bool running() const
    {
      return running_;
    }

  protected:
    void completed()
    {
      complete_ = true;
    }

    friend class Platform;

  private:
    std::atomic<bool> running_ = false;
    std::atomic<bool> complete_ = false;
  };

  static void push_task(Task* task)
  {
    worker_threads.emplace_back([task] {
        task->run();
      });
  }

	static void wait()
  {
	  for(auto& x: worker_threads)
	  {
      x.join();
	  }
  }
};
