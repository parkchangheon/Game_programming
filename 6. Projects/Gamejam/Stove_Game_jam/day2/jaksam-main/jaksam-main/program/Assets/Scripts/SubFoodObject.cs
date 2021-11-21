using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SubFoodObject : MonoBehaviour
{
    public float speed = 5f;
    FoodObject parentObject;
    public bool endDestroy = true;
    public float destroyTime = 1f;
    public void Set(FoodObject foodObject)
    {
        parentObject = foodObject;
    }

    private void Update()
    {
        //�ι�° �Ķ���Ϳ� Space.World�� �������ν� Rotation�� ���� ���� ������ ������
        transform.Translate(Vector2.right * speed * Time.deltaTime, Space.Self);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.CompareTag("Player"))
        {
            GameManager.gm.SetGuage(parentObject.healthGauge);

            if(parentObject.foodType == FOOD_TYPE.JUNK)
            {
                CameraShake.cs.Shake(0.5f);
            }

            if(endDestroy)
                Destroy(this.gameObject);
        }
    }


}
