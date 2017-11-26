class SceneEnd extends HaiScene{
    constructor(game) {
        super(game)
        game.registerAction('r', function () {
            var title = SceneTitle.new(game)
            game.replaceScene(title)  
        })
    }
    draw() {
        //draw labels
        this.game.context.fillText('游戏结束,按 r 返回标题', 150,200)
    }
    update() {
        
    }
}