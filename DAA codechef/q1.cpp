#include <bits/stdc++.h>
using namespace std;

class ques
{
public:
    int qno;
    int qmarks;
    int qsubparts;
};

bool compare(const ques &obj1, const ques &obj2)
{
    if (obj1.qsubparts != obj2.qsubparts)
        return obj1.qsubparts > obj2.qsubparts;
    else
        return obj1.qmarks < obj2.qmarks;
}

int main()
{
    int passingmarks, students, subjects;
    cin >> passingmarks >> students >> subjects;
    vector<int> studentmarks;
    for (int i = 0; i < students; ++i)
    {
        int m;
        cin >> m;
        studentmarks.push_back(m);
    }
    vector<ques> arr(subjects);
    for (int i = 0; i < subjects; ++i)
    {
        int marks, sub;
        cin >> marks >> sub;
        arr[i].qno = i + 1;
        arr[i].qmarks = marks;
        arr[i].qsubparts = sub;
    }
    sort(arr.begin(), arr.end(), compare);
    //    for (int i = 0; i < subjects; ++i) {
    //        cout<<arr[i].qno<<" ";
    //    }

    for (int i = 0; i < students; ++i)
    {
        int minmarksmarks = 0;
        int j = 0;
        vector<int> fqno;
        while (minmarksmarks < (passingmarks - studentmarks[i]))
        {
            minmarksmarks += arr[j].qmarks;
            fqno.push_back(arr[j].qno);
            j++;
        }
        cout << j << " ";
        sort(fqno.begin(), fqno.end());
        for (int k = 0; k < fqno.size(); ++k)
        {
            cout << fqno[k] << " ";
        }
        cout << endl;
    }

    return 0;
}