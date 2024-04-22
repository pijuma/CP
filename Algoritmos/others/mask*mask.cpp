// dado mask = mask1|mask2 
// como brutar tds mask1*mask2 em 3^n 
// assim só olha para as submasks de mask 
// elimina a possibilidade de um bit ativo na submask 
// e inativo na mask 
for(int mask = 0 ; mask < (1<<n) ; mask++){
    for(int mask1 = mask ; mask1 > 0 ; mask1 = (mask1-1)&mask){
        int mask2 = mask - mask1 ; 
    }
}
