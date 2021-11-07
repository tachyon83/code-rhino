const convert=s=>{
    let ret=0
    let conversion=[3600,60,1]
    s.split(':').map(e=>parseInt(e)).forEach((e,i)=>ret+=e*conversion[i])
    return ret
}

const convert2=v=>{
    let h=parseInt(v/3600)
    v-=h*3600
    h+=''
    if(h.length===1)h='0'+h
    
    let m=parseInt(v/60)
    v-=m*60
    m+=''
    if(m.length===1)m='0'+m
    
    v+=''
    if(v.length===1)v='0'+v
    
    return h+':'+m+':'+v
}

function solution(play_time, adv_time, logs) {
    const info=[],dp=[],advTime=convert(adv_time)
    
    for(let i=0;i<convert(play_time);++i){
        info.push(0)
        dp.push(0)
    }
    
    const records=[]
    for(const log of logs)log.split('-').map(e=>convert(e)).forEach((e,i)=>records.push([e,i]))
    records.sort((a,b)=>a[0]-b[0])
    
    let recordsIdx=0,acc=0
    info.forEach((e,i)=>{
        while(recordsIdx<records.length&&i===records[recordsIdx][0]){
            if(records[recordsIdx][1])acc--
            else acc++
            recordsIdx++
        }
        info[i]=acc
    })
    
    let mx=0,mxIdx=0
    dp.forEach((e,i)=>{
        let prevInfo=0,prevDp=0
        if(i-advTime>=0)prevInfo=info[i-advTime]
        if(i-1>=0)prevDp=dp[i-1]
        dp[i]=prevDp+info[i]-prevInfo
        if(dp[i]>mx){
            mx=dp[i]
            mxIdx=i
        }
    })
    
    return convert2(mxIdx-advTime+1>0?mxIdx-advTime+1:0)
}
