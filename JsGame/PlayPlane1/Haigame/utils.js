var imageFromPath = function(path){
    var img = new Image()
    img.src = path
    return img
}

var rectIntersects = function(a,b){
    if(b.y > a.y && a.image.height +a.y > b.y){
        if(b.x>a.x && b.x < a.image.width+a.x){
            return true
        }
    }
    return  false
}

const randomBetween = function (start, end) {
    var n = Math.random() * (end - start + 1)
    return Math.floor(n+start)
}




//var log = function () {
  //  e("#id-text-log").value += '\n' 
//}