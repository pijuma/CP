//computar steiner tree 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (1<<k) ; j++) dp[i][j] = inf ; 
    }

    //caso base -> estar no kra n uso aresta
    for(int i = 0 ; i < k ; i++) dp[i][(1<<i)] = 0 ; 

    for(int mask = 0 ; mask < ((1<<k)) ; mask++){ //vertices terminais unidos
        for(int i = 0 ; i < n ; i++){ // raiz -> queremos calcular dp[i][mask] 
            for(int smask = mask ; smask > 0 ; smask = (smask-1)&mask){ //submask de mask 
                    dp[i][mask] = min(dp[i][mask], dp[i][smask] + dp[i][mask-smask]) ;
                    // eh oq eu tenho usando i como raiz + o complementar 
                    //mask = smask|(mask-smask) 
                    //unindo arvores menores em maiores 
            }
            if(dp[i][mask] < inf){
                for(int j = 0 ; j < n ; j++){ // qro tentar colocar vertices n terminais na resp 
                    dp[j][mask] = min(dp[j][mask], dp[i][mask] + dist[i][j]) ; 
                }
            }
        }
    }
