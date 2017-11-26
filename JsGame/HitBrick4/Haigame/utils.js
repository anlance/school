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



//var log = function () {
  //  e("#id-text-log").value += '\n' 
//}