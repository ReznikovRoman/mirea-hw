

#include <iostream>

#include <vector>
#include <map>

#include <string>

#include <algorithm>
using namespace std;


pair<string, string> getCountryStatistics(int goldCount, int silverCount, int bronzeCount)
{
    int total = 0, score = 0;

    total = goldCount + silverCount + bronzeCount;
    score = 7 * goldCount + 6 * silverCount + 5 * bronzeCount;

    return make_pair(to_string(total), to_string(score));
}


bool compareScores(map<string, string> i, map<string, string> j)
{
    return stoi(i["Score"]) > stoi(j["Score"]);
}

void sortByScore(vector<map<string, string>> &stats)
{
    sort(stats.begin(), stats.end(), compareScores);
}


void printStatistics(vector<map<string, string>> stats)
{
    cout << endl;
    cout << "\t\tCountry\t\tGold\tSilver\tBronze\tTotal\tScore" << endl;
    for (int i = 0; i < stats.size(); ++i)
    {
        cout << '\t' << i + 1 << '\t' << stats[i]["Country"] << "\t\t" << stats[i]["Gold"] << '\t' << stats[i]["Silver"] << '\t' << stats[i]["Bronze"];
        cout << '\t' << stats[i]["Total"] << '\t' << stats[i]["Score"];
        cout << endl;
    }
    cout << endl;
}


int main()
{

    /*
    1. countryResults - словарь результатов стран (кол-во золотых, серебряных, бронзовых медалей, общее кол-во, и кол-во очков)
    2. countryList - список стран-участниц
    3. olympicStatistics - вектор со статистикой всех стран
    */

    cout << endl << "Results of the Olympic games" << endl << endl;

    map<string, string> countryResults;
    vector<map<string, string>> olympicStatistics;
    vector<string> countryList = { "Austria", "Germany", "Canada", "China", "Korea", "Norway", "Russia", "USA", "Finland", "Japan" };
    
    cout << "Enter the amount of gold, silver and bronze medals" << endl;
    for (string country : countryList)
    {
        // пользователь вводит данные о медалях для каждой страны
        cout << country << ": ";
        countryResults["Country"] = country;
        cin >> countryResults["Gold"] >> countryResults["Silver"] >> countryResults["Bronze"];

        // считаем общее кол-во медалей и кол-во очков
        pair<string, string> countryStats = getCountryStatistics(stoi(countryResults["Gold"]), stoi(countryResults["Silver"]), stoi(countryResults["Bronze"]));
        countryResults["Total"] = countryStats.first;
        countryResults["Score"] = countryStats.second;

        // записываем страну в общую статистику
        olympicStatistics.push_back(countryResults);

        // удаляем данные по текущей стране
        countryResults.clear();
    }
    cout << endl;

    // сортируем по количеству очков
    sortByScore(olympicStatistics);

    // выводим статистику на экран
    printStatistics(olympicStatistics);


    cout << endl;

    return 0;
}
