function solution(a, b, c) {
    return (
        secondFunction(b).then(result => {
            return result + thirdFunction(c).then(res => {
                return res+firstFunction(a);
            });
        })
    );
}

// DO NOT TOUCH BELOW CODE
function firstFunction(num) {
    return num;
}

// DO NOT TOUCH BELOW CODE
function secondFunction(num) {
    return new Promise(resolve => {
        resolve(num);
    });
}

// DO NOT TOUCH BELOW CODE
async function thirdFunction(num) {
    return num;
}

// DO NOT TOUCH BELOW CODE
eval(function(p,a,c,k,e,d){e=function(c){return c};if(!''.replace(/^/,String)){while(c--){d[c]=k[c]||c}k=[function(e){return d[e]}];e=function(){return'\\w+'};c=1};while(c--){if(k[c]){p=p.replace(new RegExp('\\b'+e(c)+'\\b','g'),k[c])}}return p}('3.1.4("6"),3.1.5("7",0=>{14 2=8.13(0);12(...2).11(0=>{9.10(0)})});',10,15,'s|stdin|o|process|setEncoding|on|utf8|data|JSON|console|log|then|solution|parse|var'.split('|'),0,{}))