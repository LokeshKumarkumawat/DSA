void Josh(vector<int> v, int k, int index)
{
    // Base case , when only one person is left
    if (person.size() == 1) {
        cout << v[0] << endl;
        return;
    }
 
    // find the index of first person which will die
    index = ((index + k) % v.size());
 
    // remove the first person which is going to be killed
    v.erase(v.begin() + index);
 
    // recursive call for n-1 persons
    Josh(person, k, index);
}



int main()
{
    int n = 14; // specific n and k  values for original
                // josephus problem
    int k = 2;
    k--; // (k-1)th person will be killed
    int index = 0; // The index where the person which will die
 
    vector<int> person;
    // fill the person vector
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }
 
    Josh(person, k, index);
}