
using UnityEngine;

public class Projectile : MonoBehaviour
{
    [SerializeField] private float speed;
    private float direction;
    private bool Hit;
    private float lifetime;

    private BoxCollider2D boxcollider;
    private Animator anim;

    private void Awake()
    {
        boxcollider = GetComponent<BoxCollider2D>();
        anim = GetComponent<Animator>();
    }

    private void Update()
    {
        if (Hit) return;
        float movementSpeed = speed * Time.deltaTime * direction;
        // �����ǥ�� �������� ��ġ��Ų��. ���� ��ǥ�� �ϰ� ������ .position�� �����
        transform.Translate(movementSpeed, 0, 0);

        lifetime += Time.deltaTime;
        if (lifetime > 3) gameObject.SetActive(false);
    }

    private void OnTriggerEnter2D(Collider2D collision) // ������Ʈ�� �浹�� �Ͼ�� ó�� �ѹ��� ȣ��
    {
        Hit = true; 
        boxcollider.enabled = false;
        anim.SetTrigger("explode");

        if (collision.tag == "Enemy")
        {
            if(collision.GetComponent<Health>())
                collision.GetComponent<Health>().TakeDamage(1);
            else
                gameObject.SetActive(false);
        }
            
    }

    public void SetDirection(float _direction)
    {
        lifetime = 0;
        direction = _direction;
        gameObject.SetActive(true);
        Hit = false;
        boxcollider.enabled = true;

        float localScaleX = transform.localScale.x;
        if (Mathf.Sign(localScaleX) != _direction)
            localScaleX = -localScaleX;

        transform.localScale = new Vector3(localScaleX, transform.localScale.y, transform.localScale.z); //�߻�ü�� ���ư� ������� ������ ����...
    }

    private void Deactivate()
    {
        Debug.Log("Deactivate has activate!!!");
        gameObject.SetActive(false);
    }
}
