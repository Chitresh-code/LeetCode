public TreeNode replaceValueInTree(TreeNode root) {
    if(root == null) return null;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int currentLevelSum =  root.val;
    while(!queue.isEmpty()){
        int nextLevelSum = 0;
        int size = queue.size();
        for(int i =0;i< size;i++){
            TreeNode currentNode = queue.poll();
            //sumOfCousins = currentLevelSum - sumOfSiblings stored in the currentNode 
            currentNode.val = currentLevelSum - currentNode.val;
            int leftChildValue = currentNode.left != null ? currentNode.left.val : 0;
            int rightChildValue =  currentNode.right != null ? currentNode.right.val : 0;
            int siblingSum  = leftChildValue + rightChildValue;

            if(currentNode.left != null){
                nextLevelSum += currentNode.left.val;
                currentNode.left.val = siblingSum;
                queue.offer(currentNode.left);
            }

            if(currentNode.right != null){
                nextLevelSum += currentNode.right.val;
                currentNode.right.val = siblingSum;
                 queue.offer(currentNode.right);
            }

        }
        currentLevelSum = nextLevelSum;
    }
    return root;
}