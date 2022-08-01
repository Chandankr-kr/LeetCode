class Solution {
public:
    bool isRobotBounded(string ins) {
        int x=0,y=0,n=ins.size();
        char dir='N';
        
        for(int i=0;i<n;i++){
            if(ins[i]=='G'){
                if(dir=='N'){
                    y+=1;
                }
                else if(dir=='S'){
                    y-=1;
                }
                else if(dir=='E'){
                    x-=1;
                }
                else if(dir=='W'){
                    x+=1;
                }
            }
            else{
                char temp=ins[i];
                if(dir=='N'){
                    if(temp=='L')
                        dir='E';
                    else
                        dir='W';
                }
                else if(dir=='S'){
                    if(temp=='L')
                        dir='W';
                    else
                        dir='E';
                }
                else if(dir=='E'){
                    if(temp=='L')
                        dir='S';
                    else
                        dir='N';
                }
                else if(dir=='W'){
                    if(temp=='L')
                        dir='N';
                    else
                        dir='S';
                }
            }
        }
        
        if((x==0 and y==0) or dir!='N')
            return true;
        else
            return false;
    }
};