var Scene = function (game) {
    var s = {
        game: game,
    }
    var paddle = Paddle(game)
    var ball = Ball(game)

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

    s.draw = function () {
        //draw 背景
        game.context.fillStyle = "#554"
        game.context.fillRect(0, 0, 400, 300)
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
    s.update = function () {
        ball.move()
        //判断游戏结束
        if (ball.y > paddle.y) {
            //跳转到游戏结束场景
            var end = SceneEnd(game)
            game.replaceScene(end)
        }
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
    return s
}