class SceneTitle extends HaiScene{
    constructor(game) {
        super(game)
        var label = HaiLabel.new(game, 'Hello')
        this.addElement(label)
        //game.replaceScene(s)  
        
    }
    // draw() {
    //     super.draw()
    //     //draw labels
    //     // this.game.context.fillText('按K开始游戏！', 150,200)
    // }
    update() {
        
    }
}

class HaiLabel{
    constructor(game, text) {
        this.game = game
        this.text = text
    }
    static new(game, text) {
        return new this(game, text)
    }
    draw() {
        //log('dl',this.game, this.text)
        this.game.context.fillText(this.text, 150,200)
    }
    update() {
        
    }
}

class HaiParticleSystem {
    constructor(game) {
        this.game = game
        this.setup()
    }
    setup() {
        this.x = 150
        this.y = 200
    }
    static new(game) {
        return new this(game)
    }
    draw() {
        //log('dl',this.game, this.text)
        this.game.context.fillText(this.text, 150,200)
    }
    update() {
        
    }
}