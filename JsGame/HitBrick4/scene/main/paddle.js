var Paddle = function(game){
    var o = game.imageByName('paddle')
    //var o = {
      //  image: image,
        //x: 100,
        //y: 260,
        //speed: 5,
    //}
    o.x = 100
    o.y = 250
    o.speed = 5
    o.move =  function(x){
        if(x < 0){
            x = 0
        }
        if(x > 400 - o.w){
            x = 400 - o.w
        }
        o.x = x
    }
    o.moveLeft = function(){//原文paddle.x -= paddle.speed 怎么能运行的。。。。
        o.move(o.x-o.speed)
    }
    o.moveRight = function(){
        o.move(o.x+o.speed)
    }
    var aInb = function (x, x1, x2) {
        return x>=x1 && x<=x2
    }
    o.collide = function(ball){
        var a = o
        var b = ball
        if (aInb(a.x, b.x, b.x + b.w) || aInb(b.x, a.x, a.x + a.w)) {
            if (aInb(a.y, b.y, b.y + b.h) || aInb(b.y, a.y, a.y + a.h)) {
                return true
            }
        }
        return false
    }
    return o
}