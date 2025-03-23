//vector:
//v.begin() --> points to the first element-->begin(v) also works
//++it and it++ --> go to the next element
//*it --> get the element
//v.end() --> points to the location after the last element of the v

//Traversing in reverse order
// for(auto it = v.rbegin();it!=v.rend();it++) --> Note the it++

//Constant iterator 
// auto cit = v.crbegin();
// *cit = 10 --> not allowed

//Range based for loop
// for(auto&& x:v){ --> Always use && here to avoid unnessary copying and be on the safer side 
//     cout<<x<<endl;
// }