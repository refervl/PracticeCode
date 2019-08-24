#include<cstdio>
#include<cstdlib>
#include<queue>
#define For(a,b,c,d) for(register int a=b;a<=c;a+=d) 
const int my[ 4 ] = { 0 , 1 , 0 , -1 } , mx[ 4 ] = { -1 , 0 , 1 , 0 } ; //ÿ��������ƶ����� 
int n , m , maze[ 60 ][ 60 ] ;
bool vis[ 20000 ] ; //��¼���ʹ���λ�� 
inline int fun( int a , int b , int c ) { return c * 2700 + a * 51 + b ;} //����ÿ�����Ψһ��Ӧ��keyֵ 
struct pos { //ÿ��λ�õ���Ϣ 
    int x , y ; //���� 
    int f ; //���� 
    int mov ; //���ƶ�ʱ�� 
} ;
std::queue<pos> que ; 
inline bool zq( int x , int y ) { //�ж��Ƿ�ײ���ϰ��� 
    if( maze[ x ][ y ] || maze[ x + 1 ][ y ] || maze[ x ][ y + 1 ] || maze[ x + 1 ][ y + 1 ] )
        return 1 ;
    return 0 ;
}
inline void bfs() {
    int x , y , tx , ty , f , d , mov , lx , ly ;
    char c ;
    scanf("%d %d %d %d %c" , &x , &y , &tx , &ty , &c );
    switch( c ) {
        case 'N': f = 0 ;
            break ;
        case 'E': f = 1 ;
            break ;
        case 'S': f = 2 ;
            break ;
        case 'W': f = 3 ;
            break ;
    }
    pos temp ;
    temp.x = x , temp.y = y , temp.f = f , temp.mov = 0 ;
    que.push( temp ) ;
    while( !que.empty() ) {
        temp = que.front() ;
        que.pop() ;
        x = temp.x , y = temp.y , f = temp.f , d = fun( x , y , f ) , mov = temp.mov ;
        if( x == tx && y == ty ) { //�ж��Ƿ����ص� 
            printf("%d",mov) ;
            exit( 0 ) ;
        }
        if( vis[ d ] ) //�ж��Ƿ񱻷��ʹ� 
            continue ;
        vis[ d ] = 1 ;
        temp.mov ++ ;
        temp.f = ( f + 4 - 1 ) % 4 ; //��ת 
        que.push( temp ) ;
        temp.f = ( f + 4 + 1 ) % 4 ; //��ת 
        que.push( temp ) ;
        temp.f = f ;
        For( i , 1 , 3 , 1 ) { //��ǰ�ƶ� 
            lx = x + mx[ f ] * i , ly = y + my[ f ] * i ;
            if( lx <= 0 || ly <= 0 || lx >= n || ly >= m || zq( lx , ly ) )
                break ;
            temp.x = lx ;
            temp.y = ly ;
            que.push( temp ) ;
        }
    }
    printf("-1");  
}
int main() { //������ 
    scanf("%d %d" , &n , &m ) ;
    For( i , 1 , n , 1 ) {
        For( j , 1 , m , 1 ) {
            scanf("%d", &maze[ i ][ j ] );
        }
    }
    bfs() ;
    return 0;
}
