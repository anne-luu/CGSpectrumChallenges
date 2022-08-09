//Source: https://raymii.org/s/articles/Cpp_async_threads_and_user_input.html

#include <iostream>
#include <string>
#include <future>
#include <chrono>

std::string getString()
{
    std::cout << "# getString() start\n";
    std::cout << "# getString(): Please enter a string. You have 5 seconds...\n";
    std::string input;
    std::getline(std::cin, input);
    std::cout << "# getString() end\n";
    return input;
}

int main()
{
    std::cout << "# main() start\n";
    std::cout << "# main(): Starting std::async(getString)\n";

    std::future<std::string> futureString = std::async(std::launch::async, getString);

    std::cout << "# main(): Waiting 5 seconds for input...\n";

    std::chrono::system_clock::time_point five_seconds_passed
        = std::chrono::system_clock::now() + std::chrono::seconds(5);
    std::future_status status = futureString.wait_until(five_seconds_passed);

    if (status == std::future_status::ready)
    {
        auto  result = futureString.get();
        std::cout << "# main(): Input result: " << result << "\n";
    }
    else
    {
        std::cout << "# main(): Timeout reached... \n";
    }

    std::cout << "# main() end" << std::endl;
    return 0;
}