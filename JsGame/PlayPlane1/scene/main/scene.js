class Scene extends HaiScene{
    constructor(game) {
        super(game)
        this.setup()
        this.setupInputs()
    }
    // draw() {
    //     //draw labels
    //     // this.game.drawImage(this.bg)
    //     // this.game.drawImage(this.player)
    // }
    update() {
        super.update()
        this.cloud.y += 1
    }
    setup() {
        var game = this.game
        this.numberOfEnemies = 10
        this.bg = HaiImage.new(game, 'sky')
        this.cloud = HaiImage.new(game, 'cloud')    
        // this.player = HaiImage.new(game, 'player')
        this.player = Player.new(game)
        this.player.x = 100
        this.player.y = 150

        this.addElement(this.bg)
        this.addElement(this.cloud)
        this.addElement(this.player)
        //

        this.addEnemies()
    }
    addEnemies() {
        var es = []
        for (var i = 0; i < this.numberOfEnemies; i++){
            var e = Enemy.new(this.game)
            es.push(e)
            this.addElement(e)
        }
        this.enemies = es
    }
    setupInputs() {
        var g = this.game
        var s = this
        g.registerAction('a', function () {
            s.player.moveLeft()
        })
        g.registerAction('d', function () {
            s.player.moveRight()
        })
        g.registerAction('w', function () {
            s.player.moveUp()
        })
        g.registerAction('s', function () {
            s.player.moveDown()
        })
    }
}
class Player extends HaiImage{
    constructor(game) {
        super(game, 'player')
       this.setup()
    }
    setup() {
        this.speed = 10
    }
    update() {
        
    }
    moveLeft() {
        this.x -= this.speed 
    }
    moveRight() {
        this.x += this.speed 
    }
    moveUp() {
        this.y -= this.speed 
    }
    moveDown() {
        this.y += this.speed 
    }
}

const randomBetween = function (start, end) {
    var n = Math.random() * (end - start + 1)
    return Math.floor(n+start)
}

class Enemy extends HaiImage{
    constructor(game) {
        var type = randomBetween(0, 4)
        var name = 'enemy' + type
        super(game, name)
        this.setup()
    }
    setup() {
        this.speed = randomBetween(2, 5)
        this.x = randomBetween(0, 350)
        this.y = -randomBetween(0, 200)
    }
    update() {
        this.y += this.speed
        if (this.y > 600) {
            this.setup()
        }
    }
}
// var Scene = function (game) {
//     var s = {
//         game: game,
//     }
//     var paddle = Paddle(game)
//     var ball = Ball(game)

//     var score = 0 

//     blocks = loadLevel(game, 1)

//     game.registerAction('a',function(){
//         paddle.moveLeft()
//     })
//     game.registerAction('d',function(){
//         paddle.moveRight()
//     })
//     game.registerAction('f',function(){
//         ball.fire()
//     })

//     s.draw = function () {
//         //draw 背景
//         game.context.fillStyle = "#554"
//         game.context.fillRect(0, 0, 400, 300)
//         //draw
//         game.drawImage(paddle)
//         game.drawImage(ball)
//         // draw block
//         for(var i = 0; i< blocks.length; i++){
//             var block = blocks[i]
//             if(block.alive){
//                game.drawImage(block) 
//             }    
//         } 
//         //draw labels
//         game.context.fillText('分数：'+ score,10,290)
//     }
//     s.update = function () {
//         if (window.paused) {
//             return 
//         }
//         ball.move()
//         //判断游戏结束
//         if (ball.y > paddle.y) {
//             //跳转到游戏结束场景
//             var end = SceneEnd.new(game)
//             game.replaceScene(end)
//         }
//         //判断相撞
//         if(paddle.collide(ball)){
//             ball.fantan()
//          }
//          //判断 ball 和 blocks 相撞
//          for(var i = 0; i< blocks.length; i++){
//              var block =blocks[i]
//              if(block.collide(ball)){
//                 ball.fantan()
//                 log('block 相撞')
//                  block.kill()
//                 //更新分数
//                 score += 100 
//              }
//          }
//     }
//     return s
// }