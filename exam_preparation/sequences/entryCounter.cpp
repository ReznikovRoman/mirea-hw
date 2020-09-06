

#include <iostream>

#include <vector>


std::pair<int, std::vector<int>> countEntries(std::vector<int> nums, int num)
{
    int count = 0;
    std::vector<int> indexes = {};

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == num)
        {
            count += 1;
            indexes.push_back(i);
        }
    }

    return std::make_pair(count, indexes);
}


int main()
{
    std::vector<int> nums = {1, 43, 53, 46, 46, 43, 1, 53, 7, 43, 46};
    int user_num;
    std::pair<int, std::vector<int>> entryInfo;

    std::cout << "Enter number: ";
    std::cin >> user_num;

    entryInfo = countEntries(nums, user_num);

    if (entryInfo.first == 0) { std::cout << std::endl << "There is no number " << user_num << " in the list" << std::endl; }
    else
    {
        std::cout << std::endl << "Count: " << entryInfo.first << std::endl;
        for (auto num_ind : entryInfo.second)
        {
            std::cout << "Index: " << num_ind << std::endl;
        }
    }
    
    return 0;
}
