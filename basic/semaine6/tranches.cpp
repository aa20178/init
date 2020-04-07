#include <vector>
#include <iostream>

using namespace std;
void affiche_tab(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}
void affiche_tab(vector<size_t> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}

void affiche_tab(vector<vector<int>> v2)
{
    for (int i = 0; i < v2.size(); i++)
    {
        affiche_tab(v2[i]);
        cout << endl;
    }
}

void affiche_tab(vector<vector<size_t>> v2)
{
    for (int i = 0; i < v2.size(); i++)
    {
        affiche_tab(v2[i]);
        cout << endl;
    }
}

int somme_consecutifs_max(vector<int> v)
{
    if (v.empty())
    {
        return 0;
    }
    else
    {
        int max(0), maxtemp(0);
        for (auto element : v)
        {

            if (element != 0)
            {
                maxtemp = maxtemp + element;
            }

            else
            {
                if (max < maxtemp)
                {
                    max = maxtemp;
                    maxtemp = 0;
                }
                maxtemp = 0;
            }

            //cout << "max = " << max << ", maxtemp = " << maxtemp << endl;
        }

        if (max < maxtemp)
        {
            max = maxtemp;
        }
        // cout << " enfin .. max = " << max << ", maxtemp = " << maxtemp << endl;

        return max;
    }
}

vector<size_t> lignes_max(vector<vector<int>> v)
{
    vector<int> tab_cons_max(v.size(), 0);
    vector<size_t> tab_index;

    int max_of_tcm(0);
    int index_counter(0);

    for (size_t i(0); i < v.size(); i++)
    {
        tab_cons_max[i] = somme_consecutifs_max(v[i]);

        if (tab_cons_max[i] > max_of_tcm)
        {
            max_of_tcm = tab_cons_max[i];
        }

        //cout << " ligne " << i << " max :" << max_of_tcm << " .. tab : " << tab_cons_max[i] << endl;
    }
    //affiche_tab(tab_cons_max);

    for (size_t j(0); j < tab_cons_max.size(); j++)
    {
        if (tab_cons_max[j] == max_of_tcm)
        {
            tab_index.push_back(j);
        }
    }

    //affiche_tab(tab_index);

    return tab_index;
}

vector<vector<int>> tranches_max(vector<vector<int>> v)
{
    vector<size_t> w(lignes_max(v)); //vecteur d'indexs
    vector<vector<int>> tranches;

    for (size_t i(0); i < w.size(); i++)
    {
        tranches.push_back(v[w[i]]);
    }
    return tranches;
}

int main()
{
    vector<vector<int>> u({{2, 1, 0, 2, 0, 3, 2}, {0, 1, 0, 7, 0}, {1, 0, 1, 3, 2, 0, 3, 0, 4}, {5, 0, 5}, {1, 1, 1, 1, 1, 1, 1}});
    vector<vector<int>> u2({{2, 5 ,3, 2}, {0, 1, 0, 7, 0}, {1, 0, 1, 3, 3, 0, 4}, {5, 0, 5}, {1, 1, 1, 1, 1, 1, 1}});

    vector<size_t> a = lignes_max(u2);
    affiche_tab(a);
//    vector<vector<int>> a2 = tranches_max(u);
  //  affiche_tab(a2);

    return 0;
}