class Cloud extends HaiImage{
    constructor(game) {
        super(game, 'cloud')
        this.setup()
    }
    //ss
    setup() {
        this.speed = 1
        this.x = randomBetween(0, 350)
        this.y = -randomBetween(0, 200)
    }
    update() {
        this.speed = config.cloud_speed
        this.y += this.speed
        if (this.y > 600) {
            this.setup()
        }
    }
    // debug() {
    //     this.speed = config.cloud_speed
    // }
}