#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int x, y;
	cin >> x >> y;
	int start[2];
	int fin[2];
	cin >> start[0] >> start[1] >> fin[0] >> fin[1];
	int copy[2];
	copy[0] = start[0];
	copy[1] = start[1];
	int step;
	cin >> step;
	int range[step];
	for(int i = 0; i < step; i++){
		cin >> range[i];
	}
	int k = 0;
	int ans = 0;
	int directe[step] = {0};
	directe[0] = -1;
	for(int i = 0; i < pow(4, step) - 1; i++){
		directe[0] += 1;
		for(int j = 0; j < step; j++){
			if(directe[j] > 3){
				directe[j] = 0;
				directe[j + 1] += 1;
			}
		}
		
		k = 0;
		copy[0] = start[0];
		copy[1] = start[1];
		for(int j = 0 ; j < step; j++){
			switch(directe[j]){
				case 0: 
					copy[1] += range[k];
					if(copy[1] > y){
						copy[1] -= y;
					}
					if(copy[1] < 0){
						copy[1] += y;
					}
					break;
				case 1:
					copy[0] += range[k];
					if(copy[0] > x){
						copy[0] -= x;
					}
					if(copy[0] < 0){
						copy[0] += x;
					}
					break;
				case 2:
					copy[1] -= range[k];
					if(copy[1] > y){
						copy[1] -= y;
					}
					if(copy[1] < 0){
						copy[1] += y;
					}
					break;
				case 3:
					copy[0] -= range[k];
					if(copy[0] > x){
						copy[0] -= x;
					}
					if(copy[0] < 0){
						copy[0] += x;
					}
					break;
			}
			k++;
		}
		if(copy[0] == fin[0] && copy[1] == fin[1]){
			ans = 1;
			break;
		}
	}
	
	if(ans == 1){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
