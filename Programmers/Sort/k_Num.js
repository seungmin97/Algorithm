function solution(array, commands) {
    var answer = [];


    answer =  commands.map(c=>{
        return array.slice(c[0]-1, c[1]).sort((a,b) => a-b)[c[2] - 1]
    })

    return answer;
}