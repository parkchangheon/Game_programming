
using UnityEngine;
using System.Collections;

public class FireTrap : MonoBehaviour
{
    [SerializeField] private float damage;


    [Header("Firetrap Timers")] // GUI���� ���� header�� �� �� �ְԲ� ��.(�𸮾� Category ���� ����?
    [SerializeField] private float activationDelay;
    [SerializeField] private float activeTime;
    private Animator anim;
    private SpriteRenderer spriteRend;

    private bool triggered;
    private bool active;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        spriteRend = GetComponent<SpriteRenderer>();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.tag == "Player")
        {


            if(!triggered)
            {
                //trigger the firetrap
                StartCoroutine(ActivateFiretrap());
            }

            if(active)
                collision.GetComponent<Health>().TakeDamage(damage);
        }
    }

    private IEnumerator ActivateFiretrap()
    {
        triggered = true;
        spriteRend.color = Color.red;

        yield return new WaitForSeconds(activationDelay);
        spriteRend.color = Color.white;
        active = true;
        anim.SetBool("activated", true);

        yield return new WaitForSeconds(activeTime);
        active = false;
        triggered = false;
        anim.SetBool("activated", false);

    }

}



/*����Ƽ �ڷ�ƾ
�Լ��� ȣ���ϸ� ���� ��ȯ�ϱ� ���� ���� �Ϸᰡ �ȴ�.
�̴� �Լ����� ����Ǵ� ��� �׼��� �ϳ��� ������ ������Ʈ ������ �߻��ؾ��ϴ� ���� �ǹ�

���� ��� �Ʒ��� ���� �ڵ尡 �ִٰ� �ϸ�,
    void Fade() {
    for (float f = 1f; f >= 0; f -= 0.1f)
    {
        Color c = renderer.material.color;
        c.a = f;
        renderer.material.color = c;
    }
}

���̵� �Լ��� �� ����� ���� ���Ѵ�. 
���̵��� ���� ���� �߰� ���� ������ ������ ��Ÿ���� ���� ������ �������� ���� ���ĸ� �ٿ�����.
�߰� ���� ���� ������ ������ ��ü�� ��� �������.

������ ������ ���̵带 �����ϴ� �ڵ带 update �Լ��� �߰��Ͽ� �̷� ��Ȳ�� ó���� �� �ִ�.
������ �̷� �۾��� �ڷ�ƾ�� ����ϴ� ���� �� ���ϴ�.

�ڷ�ƾ�� ������ �Ͻ� �����ϰ� unity�� ���� ������ ��ȯ�ϰ�, �����ӿ��� �ߴ��ߴ� ��ġ���� ����� �� �ִ�.

�� 

    Ienumerator Fade() {
    for (float f = 1f; f >= 0; f -= 0.1f)
    {
        Color c = renderer.material.color;
        c.a = f;
        renderer.material.color = c;
        yield return null;
    }
}

�� �ڵ忡�� IEnumerator ��ȯ Ÿ�԰� �ٵ� ��򰡿� ���Ե� yield ��ȯ������ ����Ȱ��� �� �� �ִµ�,
yield ��ȯ ������ ������ �Ͻ� �����ǰ� ���� �����ӿ��� �ٽ� ���� �Ǵ� �����̴�.*/