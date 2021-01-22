public class LFUCache {
    private Node head = null;
    private int cap = 0;
    private HashMap<Integer, Integer> keyToValue = null;
    private HashMap<Integer, Node> keyToNode = null;
    
    public LFUCache(int capacity) {
        this.cap = capacity;
        keyToValue = new HashMap<Integer, Integer>();
        keyToNode = new HashMap<Integer, Node>();
    }
    
    public int get(int key) {
        if (keyToValue.containsKey(key)) {
            increaseFrequency(key);
            return keyToValue.get(key);
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if ( cap == 0 ) return;
        if (keyToValue.containsKey(key)) {
            keyToValue.put(key, value);
            increaseFrequency(key); // updating an already existing key is also seen as accessing the key; 
                                    // so increase frequency by 1
        } else {
            if (keyToValue.size() >= cap) {
                removeOld(); // purge the least frequently used element
            }
            keyToValue.put(key, value);
            addToHead(key);
        }
    }
    
    private void addToHead(int key) {
        if (head == null) {
            head = new Node(0);
            head.keys.add(key);
        } else if (head.frequency > 0) {
            Node node = new Node(0);
            node.keys.add(key);
            node.next = head;
            head.prev = node;
            head = node;
        } else if (head.frequency == 0) {
            head.keys.add(key);
        }
        keyToNode.put(key, head);      
    }
    
    private void increaseFrequency(int key) {
        Node node = keyToNode.get(key);
        node.keys.remove(key);
        
        if (node.next == null) {
            node.next = new Node(node.frequency + 1);
            node.next.prev = node;
            node.next.keys.add(key);
        } else if (node.next.frequency == node.frequency + 1) {
            node.next.keys.add(key);
        } else {
            Node tmp = new Node(node.frequency + 1);
            tmp.keys.add(key);
            tmp.prev = node;
            tmp.next = node.next;
            node.next.prev = tmp;
            node.next = tmp;
        }

        keyToNode.put(key, node.next);
        if (node.keys.size() == 0) remove(node);
    }
    
    private void removeOld() {
        if (head == null) return;
        int old = 0;
        for (int n: head.keys) {
            old = n;
            break;
        }
        head.keys.remove(old);
        if (head.keys.size() == 0) remove(head);
        keyToNode.remove(old);
        keyToValue.remove(old);
    }
    
    private void remove(Node node) {
        if (node.prev == null) {
            head = node.next;
        } else {
            node.prev.next = node.next;
        } 
        if (node.next != null) {
            node.next.prev = node.prev;
        }
    }
    
    class Node {
        public int frequency = 0;
        public LinkedHashSet<Integer> keys = new LinkedHashSet<>();
        public Node prev = null, next = null;
        
        public Node(int frequency) {
            this.frequency = frequency;
        }
    }
}
