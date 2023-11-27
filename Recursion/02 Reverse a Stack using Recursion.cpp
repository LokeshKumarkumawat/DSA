int insert_at_bottom(int x, stack st) {
    if(st is empty) {
        st.push(x)
    }
    else {
        int a = st.top()
        st.pop()
        insert_at_bottom(x)
        st.push(a)
    }
}
void reverse(stack st) {
    if(st is not empty) {
        int x = st.top()
        st.pop()
        reverse(st)
        insert_at_bottom(x, st)
    }
}
// driver function
int[] reverseStack(int[] st) {
    reverse(st)
    return st
}