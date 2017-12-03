class Bullet extends HaiImage{
    constructor(game) {
        super(game, 'bullet')
        this.setup()
    }
    setup() {
        //this.speed = 3
        this.speed = config.bullet_speed
    }
    update() {
        this.y -= this.speed
    }
}