var Ball = function(game){
    //var image = imageFromPath('ball.png')
    var o = game.imageByName('ball')    
    o.x = 100
    o.y = 200
    o.speedX = 5
    o.speedY = 5
    o.fired = false
    o.fire = function(){
        o.fired = true
    }
    o. move = function(){
        if(o.fired){
            //log('move')
            if(o.x<0||o.x>400){
                o.speedX = -o.speedX
            }
            if(o.y<0||o.y>300){
                o.speedY = -o.speedY
            }
            //move
            o.x += o.speedX
            o.y += o.speedY
        }
    }
    o.fantan = function(){
        o.speedY *= -1        
    }
    return o
}