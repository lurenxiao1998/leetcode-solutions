#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string maximumTime(string time) {
    string a = "hh:mm";
    if (time[0] == '?') {
      if (time[1] == '?') {
        a[0] = '2';
        a[1] = '3';
      } else if (time[1] >= '4') {
        a[0] = '1';
        a[1] = time[1];
      } else {
        a[0] = '2';
        a[1] = time[1];
      }
    } else if (time[0] == '2') {
      if (time[1] == '?') {
        a[0] = time[0];
        a[1] = '3';
      }else{
        a[0] = time[0];
        a[1] = time[1];
      }
    } else {
      if (time[1] == '?') {
        a[0] = time[0];
        a[1] = '9';
      }else{
        a[0] = time[0];
        a[1] = time[1];
      }
    }

    if (time[3] == '?') {
      a[3] = '5';
    } else {
      a[3] = time[3];
    }
    if (time[4] == '?') {
      a[4] = '9';
    } else {
      a[4] = time[4];
    }
    return a;
  }
};