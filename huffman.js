class node {
    freq = 0
    Right = node
    Left = node
}
// Node is an interface of JS, so I didn't name it as Node.
class huffmanCoding {
    root = new node
    array = []
    arrNode = []

    constructor(a) {
        try {
            this.array = a.sort((x, y) => y - x)
            var sum = 0
            for (let index = 0; index < this.array.length; index++) {
                var c_newNode = new node
                c_newNode.freq = this.array[index]
                sum += this.array[index]
                c_newNode.Left = null
                c_newNode.Right = null
                this.arrNode.push(c_newNode)
            }
            this.arrNode = this.arrNode.sort((x, y) => y.freq - x.freq)
            if (Math.floor(sum) != 1.0) {
                console.log("Sum = ", sum)
                throw Error("Sum of probabilities is not equal to 1")
            }
        } catch (e) {
            console.log(e)
        }

    };

    makeTree() {
        for (let index = 0; index < this.array.length; index++) {
            var mk_newNode = new node
            if (index == this.array.length - 1) {
                this.root = this.arrNode[0]
                return
            }
            let val1 = this.arrNode[this.arrNode.length - 1].freq
            mk_newNode.Right = this.arrNode[this.arrNode.length - 1]
            this.arrNode.pop()
            let val2 = this.arrNode[this.arrNode.length - 1].freq
            mk_newNode.Left = this.arrNode[this.arrNode.length - 1]
            this.arrNode.pop()
            mk_newNode.freq = val1 + val2
            this.arrNode.push(mk_newNode)
            this.arrNode = this.arrNode.sort((x, y) => y.freq - x.freq)
        }
    };

    print() {
        this.makeTree()
        var result = {
            Frequency: [],
            HuffCoding: []
        }

        function findCode(Root, code) {
            if (Root.Left == null) {
                result.Frequency.push(Root.freq)
                result.HuffCoding.push(code)
                return
            }
            if (Root.Right == null) {
                result.Frequency.push(Root.freq)
                result.HuffCoding.push(code)
                return
            }
            findCode(Root.Left, code + '0')
            findCode(Root.Right, code + '1')
        }
        findCode(this.root, "")
        return result
    };
}

const x = [0.055, 0.055, 0.055, 0.055, 0.14, 0.14, 0.25, 0.25]
huffman = new huffmanCoding(x)
console.table(huffman.print())