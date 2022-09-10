#include "COMMON.h"

SingleLL* solve(SingleLL *head, SingleLL *curr, SingleLL *last){
    if (last->next){
        solve(head, curr, last->next);
    } else{
        return 
    }
    return head;
}
int main(){

}