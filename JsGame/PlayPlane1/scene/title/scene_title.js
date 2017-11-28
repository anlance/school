class SceneTitle extends HaiScene{
    constructor(game) {
        super(game)
        game.registerAction('k', function () {
            var s = Scene(game)
            game.replaceScene(s)  
        })
    }
    draw() {
        //draw labels
        this.game.context.fillText('按K开始游戏！', 150,200)
    }
    update() {
        
    }
}