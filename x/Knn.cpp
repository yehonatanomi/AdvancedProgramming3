//
// Created by yehonatan on 8/9/2022.
//

#include "Knn.h"

void flowerL(list<flower>* l,string fname){
    string line ;
    string  type , sepalLength ,sepalWidth ,petalLength ,petalWidth;
    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            type = "Unclassified";
            stringstream str(line);
            getline(str, sepalLength, ',');
            getline(str, sepalWidth, ',');
            getline(str, petalLength, ',');
            getline(str, petalWidth, ',');
            if (fname.compare( "classified.csv")==0) {
                getline(str, type, ',');
            }
            double x =stod(sepalLength) ;
            double y = stod(sepalWidth);
            double  z = stod(petalLength);
            double  w= stod(petalWidth);
            pointS p =pointS(x , y,z ,w);
            flower f = flower(type ,p);
            l->push_back(f);
        }
    }else{
        cout<<"Could not open the file\n";
    }
}

void flowerLFromPath(list<flower>* l,string fname){
    string line ;
    string  type , sepalLength ,sepalWidth ,petalLength ,petalWidth;
    fstream (file);
    file.open (fname);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            type = "Unclassified";
            stringstream str(line);
            getline(str, sepalLength, ',');
            getline(str, sepalWidth, ',');
            getline(str, petalLength, ',');
            getline(str, petalWidth, ',');
            double x =stod(sepalLength) ;
            double y = stod(sepalWidth);
            double  z = stod(petalLength);
            double  w= stod(petalWidth);
            pointS p =pointS(x , y,z ,w);
            flower f = flower(type ,p);
            l->push_back(f);
        }
    }else{
        cout<<"Could not open the file\n";
    }
}
void distanceL(list<flower> classified, flower unclassified, list<distanceN>* dl) {
    for (flower f:classified) {
        dl[0].push_back(distanceN(f.getType(),f.euclideanD(unclassified)));
        dl[1].push_back(distanceN(f.getType(),f.chebyshevD(unclassified)));
        dl[2].push_back(distanceN(f.getType(),f.manhattanD(unclassified)));
    }
}

bool inL(list<distanceN>* l, string s){
    for (distanceN &x: l[0]) {
        if (x.getType().compare(s) ==0){
            x.setD(x.getD() +1);
            return true;
        }
    }
    return false;
}

string  groupKnn(list<distanceN> l, int k) {
    list<distanceN> rep = l;
    list<distanceN> names;
    while (!rep.empty() && k !=0 ){
        distanceN x =rep.front();
        rep.pop_front();
        if (!inL(&names,x.getType())){
            names.push_back(distanceN(x.getType(),1));
        }
        k--;
    }
    string s;
    int max =0 ;
    while (!names.empty()){
        distanceN x =names.front();
        names.pop_front();
        if (x.getD() > max){
            s = x.getType();
            max = x.getD();
        }
    }
    return  s;
}

void knn(list<flower> classified,list<flower> unclassified, int k,list<flower>* output){
    int t =0;
    for (flower f:unclassified) {
        list<distanceN> dL[3];
        distanceL(classified, f,dL);
        for (int i = 0; i < 3; i++) {
            distanceN arr[dL[i].size()] ;
            copy(dL[i].begin(),dL[i].end(),arr);
            bubbleSort(arr,dL[i].size());
            list<distanceN> d;
            fromArrToList(&d,arr,dL[i].size());
            f.setType(groupKnn(d, k));
            output[i].push_back(f);
        }
        t++;
    }
}


void outFile(list<flower> output,string fileN){
    ofstream myfile;
    myfile.open (fileN);
    for(flower f : output) {
        myfile << f.getType()<<endl;
    }
    myfile.close();
}

void fromArrToList(list<distanceN>* d, distanceN arr[], int size){
    for (int i=0; i<size ;i++) {
        d->push_back(arr[i]);
    }
}

void bubbleSort(distanceN arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].getD() > arr[j + 1].getD())
                swap(arr[j], arr[j + 1]);
}



list<flower> fromStoL(string s){
    list<flower> l ;
    string  type , sepalLength ,sepalWidth ,petalLength ,petalWidth;
    stringstream str(s);
    while(getline(str, sepalLength, ','))
    {
        getline(str, sepalWidth, ',');
        getline(str, petalLength, ',');
        getline(str, petalWidth, ',');
        getline(str, type, ',');
        double x =stod(sepalLength) ;
        double y = stod(sepalWidth);
        double  z = stod(petalLength);
        double  w= stod(petalWidth);
        pointS p =pointS(x , y,z ,w);
        flower f = flower(type ,p);
        l.push_back(f);
    }
    return l;
}

string fromLtoS(list<flower> l){
    string s;
    s = l.front().toString();
    l.pop_front();
    for (flower f:l) {
        s+="," + f.toString();
    }
    return s;
}