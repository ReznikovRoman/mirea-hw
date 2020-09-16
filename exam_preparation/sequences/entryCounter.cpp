

#include <iostream>

#include <vector>

using namespace std;


pair<int, vector<int>> countEntries(const vector<int> &nums, const int &num)
{
    int count = 0;
    vector<int> indexes = {};

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == num)
        {
            count += 1;
            indexes.push_back(i);
        }
    }

    return make_pair(count, indexes);
}


int main()
{
    vector<int> nums = { 1, 43, 53, 46, 46, 43, 1, 53, 7, 43, 46 };
    int user_num;
    pair<int, vector<int>> entryInfo;

    cout << "Enter number: ";
    cin >> user_num;

    entryInfo = countEntries(nums, user_num);

    if (entryInfo.first == 0) { cout << endl << "There is no number " << user_num << " in the list" << endl; }
    else
    {
        cout << endl << "Count: " << entryInfo.first << endl;
        for (auto num_ind : entryInfo.second)
        {
            cout << "Index: " << num_ind << endl;
        }
    }

    return 0;
}
