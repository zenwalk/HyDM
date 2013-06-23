///////////////////////////////////////////////////////////
//  AnnotationLayer.cs
//  Implementation of the Class AnnotationLayer
//  Generated by Enterprise Architect
//  Created on:      08-四月-2011 13:45:29
//  Original author: Administrator
///////////////////////////////////////////////////////////




using DIST.DGP.DataExchange.VCT.ESRIData;
using DIST.DGP.DataExchange.VCT.FileData;
using System.Collections.Generic;
using System;
using ESRI.ArcGIS.Geodatabase;
namespace DIST.DGP.DataExchange.VCT.ESRIData {
	/// <summary>
	/// 注记图层类
	/// </summary>
	public class AnnotationLayer : FeatureLayer {

		public AnnotationEntity m_AnnotationEntity;

		public AnnotationLayer(){

		}

		~AnnotationLayer(){

		}

		public override void Dispose()
        {
            base.Dispose();
		}

        /// <summary>
        /// 创建
        /// </summary>
        public override bool Create(TableStructureNode tableStructureNode)
        {
            base.Create(tableStructureNode);

            return true;
        }

		/// <summary>
		/// 创建注记实体
		/// </summary>
		/// <param name="entinyNode">VCT注记实体节点</param>
		public override FeatureEntity CreateFeatureEntity(EntityNode entinyNode)
        {
            try
            {
                if (entinyNode is AnnotationNode)
                {
                    m_AnnotationEntity = new AnnotationEntity();
                    m_AnnotationEntity.SetFeatureKeyFieldName(m_strEntityFieldName, m_strSYDMFieldName);
                    m_AnnotationEntity.CreateFeature(this.Table, entinyNode);

                    return m_AnnotationEntity;
                }
                else
                    return null;
            }
            catch(Exception ex)
            {
                LogAPI.WriteErrorLog(ex);
                return null;
            }
		}

        /// <summary>
        /// 获取实体集合
        /// </summary>
        public override List<FeatureEntity> GetFeatureEntitys()
        {
            try
            {
                IFeatureClass pFeatureCls = this.Table as IFeatureClass;
                IFeatureCursor pCursor = pFeatureCls.Search(null,false);
                IFeature pFeature=  pCursor.NextFeature();
                List<FeatureEntity> listFeatureEnty = new List<FeatureEntity>();//保存FeatureEntity
                while (pFeature!=null)
                {
                    AnnotationEntity pAnnotationEntity = new AnnotationEntity();
                    pAnnotationEntity.Feature = pFeature;
                    ///初始化相关数据
                    //pAnnotationEntity.GetEntityNode();
                    pAnnotationEntity.FeatureCode = this.FeatureCode;


                    int nEntityIDIndex = -1;
                    nEntityIDIndex = pFeature.Fields.FindField(m_strEntityFieldName);
                    if (nEntityIDIndex != -1)
                        pAnnotationEntity.EntityID = Convert.ToInt32(pFeature.get_Value(nEntityIDIndex));

                    ///获取标识码和要素代码字段
                    pAnnotationEntity.SetFeatureKeyFieldName(m_strEntityFieldName, m_strSYDMFieldName);

                    listFeatureEnty.Add(pAnnotationEntity);
                    pFeature = pCursor.NextFeature();
                }
                m_FeatureEntys = listFeatureEnty;
                return listFeatureEnty;
            }
            catch(Exception ex)
            {
                LogAPI.WriteErrorLog(ex);
                return null;
            }
        }

	}//end AnnotationLayer

}//end namespace ESRIData