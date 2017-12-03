class HaiScene{
    constructor(game) {
        this.game = game
        this.debugModeEnabled = true
        this.elements = []
    }
    draw() {
        for (var i = 0; i < this.elements.length; i++){
            var e = this.elements[i]
            // this.game.drawImage(e)
            e.draw()
        }
        log('e', this.elements.length )
    }
    static new(game) {
        var i = new this(game)
        return i
    }
    addElement(img) {
        img.scene = this
        this.elements.push(img)
    }
    update() {
        // if (this.debugModeEnabled) {
        //     for (var i = 3; i < this.elements.length; i++){//i=3是因为前面有3个元素不是enemy
        //         var e = this.elements[i]
        //         e.debug && e.debug()
        //     }
        // }
        for (var i = 3; i < this.elements.length; i++){//i=3是因为前面有3个元素不是enemy
            var e = this.elements[i]
            e.update()
        }
    }
}
