using UnityEngine;
using System.Collections;

public class TextureScroll : MonoBehaviour {

	//GameObject ground;
	//Material groundMat;

	public float scrollSpeed = 0.005f;

	// Use this for initialization
	void Start () {
		//ground = GameObject.Find("Ground");
		//groundMat = ground.gameObject.renderer.material;
	}
	
	// Update is called once per frame
	void Update () {
		//groundMat.
		float offset = Time.time * scrollSpeed;
		renderer.material.SetTextureOffset("_MainTex", new Vector2(0,-offset));
		renderer.material.SetTextureOffset("_BumpMap", new Vector2(0,-offset));
		renderer.material.SetTextureOffset("_HeightMap", new Vector2(0,-offset));
	}
}
