var log = console.log.bind(console)

var loadLevel = function(game, n){
    n = n - 1
    var level = levels[n]
    log(level)
    var blocks = []
    for(var i = 0; i < level.length; i++){
        var p = level[i]
        var b = Block(game,p)        
        //设置 block 坐标
        blocks.push(b)
    }
    return blocks
}

var blocks = []
var enableDebugMode = function(game, enable){
    if(!enable){
        return 
    }
    window.paused = false
    window.addEventListener('keydown', function(event){
        log('event.key')
        var k = event.key
        if(k == 'p'){
            //暂停功能
            paused = (!paused)
        }else if ('1234567'.includes(k)){
            //载入关卡
            blocks = loadLevel(game, Number(k))
        }
    })
    //控制速度
    document.querySelector('#id-input-speed').addEventListener('input', function(){
        var input = event.target
        //log(event,input.value)
        window.fps = Number(input.value)
    })
}

var __main = function(){

    
    var images = {
        ball: "ball.png",
        block: "block.png",
        paddle: "paddle.png",
    }
    var game = HaiGame(60, images, function (g) {
        var paddle = Paddle(game)
        var ball = Ball(game)
        //var block = Block()
    
        var score = 0 
    
        blocks = loadLevel(game, 1)
        
        game.registerAction('a',function(){
            paddle.moveLeft()
        })
        game.registerAction('d',function(){
            paddle.moveRight()
        })
        game.registerAction('f',function(){
            ball.fire()
        })
        
        
        game.update = function(){
            if(paused){
                return 
            }
            ball.move()
            //判断相撞
            if(paddle.collide(ball)){
               ball.fantan()
            }
            //判断 ball 和 blocks 相撞
            for(var i = 0; i< blocks.length; i++){
                var block =blocks[i]
                if(block.collide(ball)){
                   ball.fantan()
                   log('block 相撞')
                    block.kill()
                   //更新分数
                   score += 100 
                }
            }
           
        }
    
        game.draw = function(){
            //draw
            game.drawImage(paddle)
            game.drawImage(ball)
            // draw block
            for(var i = 0; i< blocks.length; i++){
                var block = blocks[i]
                if(block.alive){
                   game.drawImage(block) 
                }    
            } 
            //draw labels
            game.context.fillText('分数：'+ score,10,290)
        }
    })
    enableDebugMode(game, true)  
}

__main()
