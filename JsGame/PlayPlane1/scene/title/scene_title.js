class SceneTitle extends HaiScene{
    constructor(game) {
        super(game)
        var label = HaiLabel.new(game, 'Hello')
        this.addElement(label)
        //game.replaceScene(s)  
        
        var ps = HaiParticleSystem.new(game)
        log('ps',ps)
        this.addElement(ps)
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
        log('7')
    }
}

class HaiParticle extends HaiImage{
    constructor(game, name) {
        super(game, 'fire')
        this.setup()
    }
    setup() {
        log('9')
    }
    update() {
        log('1',this.x, this.y)
        this.x += this.vx
        this.y += this.vy
    }
    init(x, y, vx, vy) {
        log('2',this.x, this.y)
        this.x = x
        this.y = y
        this.vx = vx
        this.vy = vy
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
        this.numberOfParticles = 20
        this.particles = []
        log('3',this.x,this.y)
    }
    static new(game) {
        return new this(game)
    }
    draw() {
        //log('44',this.particles.length)
        for (var p of this.particles) {
            log('6', this.x, this.y)
            p.draw()
        }
        //log('4',this.x,this.y)
    }
    update() {
        //添加小火花
        log('5',this.x,this.y)
        if (this.particles.length < this.numberOfParticles) {
            var p = HaiParticle.new(this.game)
            //设置
            var vx = randomBetween(-10,10)
            var vy = randomBetween(-10,10)
            p.init(this.x, this.y, vx, vy)
            log('p',p)
            this.particles.push(p)
        }
        //更新所有火花
        for (var p of this.particles) {
            p.update()
        }
    }
}